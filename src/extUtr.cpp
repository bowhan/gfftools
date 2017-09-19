#include <cstdio>
#include "gff.h"
#include <zlib.h>
#include "htslib/kseq.h"
#include <unordered_map>
#include <utility>
#include <string>

KSEQ_INIT(gzFile, gzread)

using namespace std;

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr
                , "this script takes a gtf/gff file and print to stdout the fasta with 3' UTR\nusage:\n\t %s  gtf/gff transcriptom_fa\n"
                , argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE *fh = fopen(argv[1], "r");
    gzFile fp = gzopen(argv[2], "r");

    if (!fh || !fp) {
        fprintf(stderr, "error: failed to open %s for reading\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    kseq_t *seq = kseq_init(fp);

    GffReader gffreader;
    gffreader.init(fh, true);
    gffreader.readAll();

    unordered_map<string, string> mrna2seq;
    while (kseq_read(seq) >= 0) {
        mrna2seq.insert(pair<string, string>{seq->name.s, seq->seq.s});
    }
    kseq_destroy(seq);
    gzclose(fp);
    uint cds_start, cds_end;
    for (unsigned int i = 0; i < gffreader.gflst.Count(); ++i) {
        GffObj *p_gffobj = gffreader.gflst.Get(i);
        if (!p_gffobj->hasCDS())
            continue;
        p_gffobj->mRNA_CDS_coords(cds_start, cds_end);
        auto f = mrna2seq.find(string(p_gffobj->getID()));
        if (f != mrna2seq.end()) {
            fprintf(stdout, ">%s\n%s\n"
                    , f->first.c_str()
                    , f->second.substr(cds_end).c_str());
        }
    }
    return EXIT_SUCCESS;
}
