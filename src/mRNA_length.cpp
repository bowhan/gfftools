#include <cstdio>
#include "gff.h"

using namespace std;

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr
                , "this script takes a gtf/gff file and print to stdout the length of each mRNA\nusage:\n\t %s  gtf/gff\n"
                , argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE *fh = fopen(argv[1], "r");
    if (!fh) {
        fprintf(stderr, "error: failed to open %s for reading\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    GffReader gffreader;
    gffreader.init(fh, true);
    gffreader.readAll();
    unsigned int mrna_len;
    for (unsigned int i = 0; i < gffreader.gflst.Count(); ++i) {
        GffObj *p_gffobj = gffreader.gflst.Get(i);
        mrna_len = 0;
        for (unsigned int j = 0; j < p_gffobj->exons.Count(); ++j) {
            mrna_len += p_gffobj->exons[j]->len();
        }
        printf("%s\t%s\t%s\t%d\n", p_gffobj->getGeneID(), p_gffobj->getGeneName(), p_gffobj->getID(), mrna_len);
    }
    return EXIT_SUCCESS;
}