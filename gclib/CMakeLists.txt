set(GCLIB_SRC
        GArgs.cpp
        GBase.cpp
        gdna.cpp
        gff.cpp
        GList.hh
        GStr.cpp
        GVec.hh
        GFastaIndex.cpp
        GHash.hh
        GFaSeqGet.cpp
        codons.cpp
        )

set(GCLIB_HEADER
        AceParser.h
        codons.h
        GAlnExtend.h
        GArgs.h
        GBam.h
        GBase.h
        GBitVec.h
        gcdb.h
        GCdbYank.h
        gdimg.h
        gdna.h
        GFaSeqGet.h
        GFastaFile.h
        GFastaIndex.h
        gff.h
        gstopwatch.h
        GStr.h
        GThreads.h
        LayoutParser.h
        proc_mem.h
        )


add_library(gclib
        SHARED
        ${GCLIB_HEADER}
        ${GCLIB_SRC}
        )

add_library(gclib_static
        STATIC
        ${GCLIB_HEADER}
        ${GCLIB_SRC}
        )

set_target_properties(gclib PROPERTIES OUTPUT_NAME "gclib")

install(TARGETS gclib gclib_static
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
