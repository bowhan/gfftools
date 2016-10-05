#include <stdio.h>
#include <stdlib.h>
#include "gff.h"

using namespace std;

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage:\n\t%s gtf_file\n", argv[0]);
        return 1;
    }
    FILE *fh = fopen(argv[1], "r");
    if (!fh) {
        fprintf(stderr, "cannot open file %s \n", argv[1]);
        exit(1);
    }
    GffReader gffreader;
    gffreader.init(fh, true);
    gffreader.readAll();
    for (unsigned int i = 0; i < gffreader.gflst.Count(); ++i) {
        GffObj *pgff = gffreader.gflst.Get(i);

        printf("%s\t"
                   "%s\t"
                   "%s\t"
                   "%c\t"
                   "%u\t"
                   "%u\t"
                   "%u\t"
                   "%u\t"
                   "%d\t"
               , pgff->getGeneName()
               , pgff->getID()
               , pgff->getRefName()
               , pgff->strand
               , pgff->start - 1
               , pgff->end
               , pgff->hasCDS() ? pgff->CDstart - 1 : pgff->end
               , pgff->hasCDS() ? pgff->CDend : pgff->end
               , pgff->exons.Count()
        );
        // print exon start positions
        for (int j = 0; j < pgff->exons.Count(); ++j) {
            printf("%d,", pgff->exons[j]->start - 1);
        }
        printf("\t");
        // print exon end positions
        for (int j = 0; j < pgff->exons.Count(); ++j) {
            printf("%d,", pgff->exons[j]->end);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}