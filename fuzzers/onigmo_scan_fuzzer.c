#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "onigmo.h"
#include "regint.h"

static int
scan_callback(OnigPosition n, OnigPosition r, OnigRegion* region, void* arg){
        return 0;
}

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {

        if(size<3){
                return 0;
        }

        char *new_str = (char *)malloc(size+1);

        if (new_str == NULL){
                return 0;
        }
        memcpy(new_str, data, size);
        new_str[size] = '\0';

        regex_t* reg;
        UChar* str = (UChar* )new_str;
        UChar* end = str + strlen(new_str);
        OnigErrorInfo einfo;

        int new_onig = onig_new(&reg, str, end,
                                ONIG_OPTION_DEFAULT, ONIG_ENCODING_ASCII,
                                ONIG_SYNTAX_DEFAULT, &einfo);

        if (new_onig != ONIG_NORMAL) {
                free(new_str);
                return 0;
        }

        OnigRegion *region = onig_region_new();

        int fuzzer = onig_scan(reg, &str[1], NULL, region,
                               ONIG_OPTION_NONE, scan_callback, NULL);

        onig_region_free(region, 1);
        onig_free(reg);
        free(new_str);
        return 0;
}
