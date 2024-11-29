#ifndef _CTYPE_IMPL_H
#define _CTYPE_IMPL_H
  
#define   UPPER     0x01
#define   LOWER     0x02
#define   DIGIT     0x04
#define   XDIGIT    0x08
#define   PUNCT     0x10
#define   SPACE     0x20
#define   PRINT     0x40
#define   CNTRL     0x80

extern const int ct_arr[];

#define   ISUPPER(c)  (ct_arr[(c)] & UPPER)
#define   ISLOWER(c)  (ct_arr[(c)] & LOWER)
#define   ISALPHA(c)  (ct_arr[(c)] & (LOWER | UPPER))
#define   ISDIGIT(c)  (ct_arr[(c)] & DIGIT)
#define   ISALNUM(c)  (ct_arr[(c)] & (LOWER | UPPER | DIGIT))
#define   ISXDIGIT(c) (ct_arr[(c)] & XDIGIT)
#define   ISPUNCT(c)  (ct_arr[(c)] & PUNCT)
#define   ISSPACE(c)  (ct_arr[(c)] & SPACE)
#define   ISPRINT(c)  (ct_arr[(c)] & PRINT)
#define   ISCNTRL(c)  (ct_arr[(c)] & CNTRL)

#endif // _CTYPE_IMPL_H