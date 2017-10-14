## Tools to manipulate GTF/GFF formats
Mostly uses [gpertea's excellent gclib library](https://github.com/gpertea/gclib).

### To compile

```bash
mkdir build && cd build 
cmake -DCMAKE_INSTALL_PREFIX=$HOME -DCMAKE_BUILD_TYPE=Release .. 
make && make install
```

### modules

`mRNA_length`: **output lengths of each mRNA with its mRNA and gene name** <br>

#### usage
```bash
mRNA_length hg19.genes.gtf > hg19.genes.info.tsv 
```


`gff2refFlat`: **convert from gtf/gff to refFlat** <br>
_refFlat is mostly used by piccard to calculate RNA coverage_

#### usage
```bash
gff2refFlat hg19.genes.gtf > hg19.refFlat.txt
```

`extUtr`: **extract 3' UTR sequence**<br>

#### usage
```bash
extUtr mm10.genes.gtf mm10.genes.fa > mm10.3UTR.fa
# mm10.genes.fa can be obtained using gffread, which can be found in Cufflink package
```