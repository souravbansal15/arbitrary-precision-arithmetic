#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include"arbprecision.h"
#include "time.h"
#include <complex.h>
#include <math.h>

void execute(char* a[5],FILE *tFile){
    clock_t t;
    t=clock();
    long double complex z1 = strtold(a[1],NULL) + strtold(a[2],NULL) * I;
    if(strcmp(a[0],"ADD")==0){
        long double complex z2 = strtold(a[3],NULL) + strtold(a[4],NULL) * I;
        long double complex sum = z1 + z2;
        //printf("The sum: Z1 + Z2 = %.2f %+.2fi\n", creal(sum), cimag(sum));
    }else if(strcmp(a[0],"SUB")==0){
        long double complex z2 = strtold(a[3],NULL) + strtold(a[4],NULL) * I;
        long double complex diff = z1 - z2;
        //printf("The difference: Z1 - Z2 = %.2f %+.2fi\n", creal(diff), cimag(diff));
    }else if(strcmp(a[0],"PROD")==0){
        long double complex z2 = strtold(a[3],NULL) + strtold(a[4],NULL) * I;
        long double complex prod = z1 * z2;
        //printf("The product: Z1 * Z2 = %.2f %+.2fi\n", creal(prod), cimag(prod));
    }else if(strcmp(a[0],"QUOT")==0){
        long double complex z2 = strtold(a[3],NULL) + strtold(a[4],NULL) * I;
        long double complex quo = z1 / z2;
        //printf("The quotient: Z1 / Z2 = %.2f %+.2fi\n", creal(quo), cimag(quo));
    }else if(strcmp(a[0],"ABS")==0){
        long double complex conjugate = conj(z1);
        long double complex prod = z1 * conjugate;
        // double complex z1 = csqrtl(creal(prod));
        // printf("Square root of %.1f\n", creal(z1));
        long double sqroot = sqrt(creal(prod));
        //printf("The absolute: %Lf\n", sqroot);
    }
    t=clock()-t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    //printf("total time taken when automatic = %f\n",time_taken);
    fprintf(tFile,"%f", time_taken);
    fprintf(tFile, "\n");
}
void parse_complex(char* a[5],FILE *tFile,FILE *outfile){
    clock_t t;
    t=clock();
    printf("\n");
    if(strcmp(a[0],"ADD")==0){
        char *n1=add_h(a[1],a[3]);
        char *n2=add_h(a[2],a[4]);
        t=clock()-t;
        fprintf(outfile,"(%s,%s)\n",n1,n2);
        printf("addition_complex %s + i * %s\n",n1,n2);
    }else if(strcmp(a[0],"SUB")==0){
        char *n1=sub_h(a[1],a[3]);
        char *n2=sub_h(a[2],a[4]);
        t=clock()-t;
        fprintf(outfile,"(%s,%s)\n",n1,n2);
        printf("substraction_complex %s + i * %s\n",n1,n2);
    }else if(strcmp(a[0],"PROD")==0){
        char *n1=mul_h(a[1],a[3]);
        char *n2=mul_h(a[2],a[4]);
        char *n3=mul_h(a[2],a[3]);
        char *n4=mul_h(a[1],a[4]);
        char *real=sub_h(n1,n2);
        char *imag=add_h(n3,n4);
        t=clock()-t;
        fprintf(outfile,"(%s,%s)\n",real,imag);
        printf("multiplication_complex -> real part => %s\n",real);
        printf("multiplication_complex -> imaginary part => %s\n",imag);
    }else if(strcmp(a[0],"QUOT")==0){
        //numberator
        //printf("%s\n",a[1]);
        char *n1=mul_h(a[1],a[3]);
        //printf("||%s\n",n1);
        char *n2=mul_h(a[2],a[4]);
        //printf("||%s\n",n2);
        char *n3=mul_h(a[2],a[3]);
        //printf("||%s\n",n3);
        char *n4=mul_h(a[1],a[4]);
        //printf("||%s\n",n4);
        char *real=add_h(n1,n2);
        char *imag=sub_h(n3,n4);
        //printf("\nnumerator real = %s, imag = %s\n",real,imag);
        //denominator
        char *n5=mul_h(a[3],a[3]);
        char *n6=mul_h(a[4],a[4]);
        char *den=add_h(n5,n6);
        //printf("\ndenominator %s\n",den);
        //result
        char *realDiv=div_h(real,den);
        char *imagDiv=div_h(imag,den);
        t=clock()-t;
        fprintf(outfile,"(%s,%s)\n",realDiv,imagDiv);
        //printf("\ndivision_complex->real_num => %s , imag_num => %s , den = %s\n",real,imag,den);
        printf("\ndivision_complex-> final result -> real => %s , imag => %s\n",realDiv,imagDiv);
    }else if(strcmp(a[0],"ABS")==0){
        char *n1=mul_h(a[1],a[1]);
        char *n2=mul_h(a[2],a[2]);
        char *n3=add_h(n1,n2);
        char *sqrt=sqrt_h(n3);
        t=clock()-t;
        fprintf(outfile,"(%s,0)\n",sqrt);
        printf("absolute is %s\n",sqrt);
    }
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    //printf("total time taken = %f\n",time_taken);
    fprintf(tFile,"%f", time_taken);
    fprintf(tFile, "  ");
}
int main(int argc,char *argv[]){
    FILE *infile,*timeFile,*outfile; 
    char c[100000];
    infile = fopen (argv[1], "r");
    outfile = fopen(argv[2], "w");
    timeFile = fopen("time.dat", "w");
    fprintf(timeFile, "Inst arbprecisionLibrary  ComplexLibrary\n");
    if (infile == NULL) 
    { 
        fprintf(stderr, "\nError opening file\n"); 
        exit (1); 
    }
    char* a[5];
    while (fgets(c, sizeof c, infile)!= NULL){
        
        if(c[strlen(c)-1]=='\n'){
            c[strlen(c)-1]='\0';
        }
        char *ptr = strtok(c, " ,()");
        int l=0;
        while(ptr != NULL){
            a[l]=ptr;
            l++;
            ptr = strtok(NULL, " ,()");
        }
        // for(int i=0;i<5;i++){
        //     printf("%s\n",a[i]);
        // }
        fprintf(timeFile, a[0]);
        fprintf(timeFile, " ");
        parse_complex(a,timeFile,outfile);
        execute(a,timeFile);
    }
    // closing the file
    fclose (infile);
    fclose (timeFile);
    fclose (outfile);
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    fprintf(gnuplotPipe,"set terminal png\n");
    fprintf(gnuplotPipe,"set output \"%s\"\n",argv[3]);
    fprintf(gnuplotPipe,"set title \"Comparison between Time Taken to execute the instructions\"\n");
    fprintf(gnuplotPipe,"set style data histogram\n");
    fprintf(gnuplotPipe,"set style fill solid\n");
    fprintf(gnuplotPipe,"set style histogram clustered\n");
    fprintf(gnuplotPipe,"plot for [COL=2:3] \"time.dat\" using COL:xticlabels(1) title columnheader fs pattern 2`\n");
    return 0;
}