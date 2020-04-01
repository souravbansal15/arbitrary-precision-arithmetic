#ifndef ARBPRECISION_H
#define ARBPRECISION_H
    char* substring(int l, int h, char* d);
    int allZero(char* curr);
    char* removeLead(char* ans);
    void removel(char* ans);
    int greater(char* dividend, char* divisor);
    int greaterS(char* dividend, char* divisor);
    int removePointDiv(char* cargs[3]);
    void rev(char* str);
    void trim(char* cargs[3]);
    int orderNumbers(char* cargs[3]);
    void complete(char* cargs[3]);
    int compare(char* s1, char* s2);
    int removePoint(char* cargs[3]);
    char* addnew(char* n1,char* n2,char* ans);
    char* subnew(char *n1, char *n2, char* ans);
    char* mulByChar(int c1, char* st,char *curr);
    char* mulnew(char* cargs[3], char* ans);
    int findQ(char* a, char* d);
    char* divnew(char* cargs[3], char* ans);
    char* add_h(char *s1,char *s2);
    char* sub_h(char *s1,char *s2);
    char* mul_h(char *s1, char *s2);
    char* div_h(char *s1, char *s2);
    int preprocess(char* s);
    void find(char *a, char *q,char *curr, int i);
    char* sqrtn(char *st,char *ans);
    char* sqrt_h(char *s);
#endif
