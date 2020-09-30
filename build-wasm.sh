clang \
   --target=wasm32 \
   -Oz \
   -flto \
   -nostdlib \
   -Wl,--no-entry \
   -Wl,--export-all \
   -Wl,--lto-O3 \
   -Wl,-z,stack-size=$[8 * 1024 * 1024] \
   -o onigmo.wasm \
   -I wasm -I . -I enc/unicode -Wl,-error-limit=0 \
	regparse.c regcomp.c regexec.c regext.c \
	regenc.c regtrav.c regversion.c st.c \
	enc/unicode.c enc/ascii.c enc/utf_8.c \
	enc/utf_16be.c enc/utf_16le.c \
 	enc/utf_32be.c enc/utf_32le.c enc/iso_8859_1.c \
        wasm/stdlib.c
wasm-strip onigmo.wasm

# regsyntax.c
# enc/euc_jp.c enc/shift_jis.c wasm/stdlib.c
# enc/unicode/casefold.h enc/unicode/name2ctype.h \
# regerror.c regposerr.c regposix.c reggnu.c \
# regint.h regparse.h regenc.h st.h \
# enc/shift_jis.h \
# enc/windows_31j.c \
# enc/jis/props.h enc/jis/props.kwd \
# enc/iso_8859.h
# enc/iso_8859_2.c  enc/iso_8859_3.c \
# enc/iso_8859_4.c  enc/iso_8859_5.c \
# enc/iso_8859_6.c  enc/iso_8859_7.c \
# enc/iso_8859_8.c  enc/iso_8859_9.c \
# enc/iso_8859_10.c enc/iso_8859_11.c \
# enc/iso_8859_13.c enc/iso_8859_14.c \
# enc/iso_8859_15.c enc/iso_8859_16.c \
# enc/euc_tw.c enc/euc_kr.c enc/big5.c \
# enc/gb18030.c enc/koi8_r.c enc/koi8_u.c \
# enc/windows_1250.c enc/windows_1251.c \
# enc/windows_1252.c enc/windows_1253.c \
# enc/windows_1254.c enc/windows_1257.c
