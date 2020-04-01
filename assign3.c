#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#define max(x,y) (((x) > (y)) ? (x) : (y))

char* substring(int l, int h, char* d){
    char* temp=malloc(h-l+2);
    int i=0;
    for(i=l;i<=h;i++){
        temp[i-l]=d[i];
    }
    temp[i-l]='\0';
    return temp;
}
int allZero(char* curr){
    for(int i=0;i<strlen(curr);i++){
        if(curr[i]!='0'){
            return 0;
        }
    }
    return 1;
}
char* removeLead(char* ans){
    int count=0;
    for(int k=0;k<strlen(ans)-1;k++){
        if(ans[k]=='0' && ans[k+1]!='.'){
            count++;
        }else{
            break;
        }
    }
    //printf("count%d\n",count);
    char* an=substring(count,strlen(ans),ans);
    //printf("%s\n",an);
    return an;
}
void removel(char* ans){
    int count=0;
    for(int k=0;k<strlen(ans)-1;k++){
        if(ans[k]=='0' && ans[k+1]!='.'){
            count++;
        }else{
            break;
        }
    }
    //printf("count%d\n",count);
    int i=0;
    for(i=0;i<=strlen(ans)-1-count;i++){
        ans[i]=ans[i+count];
    }
    ans[i]='\0';
}
int greater(char* dividend, char* divisor){
    //printf("            in fucntion%ld,%ld---\n",strlen(divisor),strlen(dividend));
    if(strlen(divisor)<strlen(dividend)){
        return 1;//--> current part of the dividend is greater
    }else if(strlen(divisor)>strlen(dividend)){
        return 0;//--> current part of the dividend is smaller
    }else{
        //printf("            inelse\n");
        for(int i=0;i<=strlen(divisor);i++){
            //printf("            divisor[]=%c,res[]=%c,i=%d\n",divisor[i],dividend[i],i);
            if(divisor[i]>dividend[i]){
                //printf("            ||%d|| here it returns 0\n",i);
                return 0;
            }else if(divisor[i]<dividend[i]){
                return 1;
            }
        }
        return 1;
    }
}
int greaterS(char* dividend, char* divisor){
    //printf("            in fucntion%ld,%ld---\n",strlen(divisor),strlen(dividend));
    if(strlen(divisor)<strlen(dividend)){
        return 1;//--> current part of the dividend is greater
    }else if(strlen(divisor)>strlen(dividend)){
        return 0;//--> current part of the dividend is smaller
    }else{
        //printf("            inelse\n");
        for(int i=0;i<=strlen(divisor);i++){
            //printf("            divisor[]=%c,res[]=%c,i=%d\n",divisor[i],dividend[i],i);
            if(divisor[i]>dividend[i]){
                //printf("            ||%d|| here it returns 0\n",i);
                return 0;
            }else if(divisor[i]<dividend[i]){
                return 1;
            }
        }
        return -1;
    }
}
int removePointDiv(char* cargs[3]){
    int b1=0,b2=0,i=0,j=0,count=0;
    for(i=0;i<strlen(cargs[1])-1;i++){
        if(cargs[1][i]=='.'){
            b1=1;
            count+=(strlen(cargs[1])-i-1);
        }
        if(b1==1){
            cargs[1][i]=cargs[1][i+1];
        }
    }
    if(b1==1){
        cargs[1][i]='\0';
    }
    for(j=0;j<strlen(cargs[2])-1;j++){
        if(cargs[2][j]=='.'){
            b2=1;
            count-=(strlen(cargs[2])-j-1);
        }
        if(b2==1){
            cargs[2][j]=cargs[2][j+1];
        }
    }
    if(b2==1){
        cargs[2][j]='\0';
    }
    return count;
}
void rev(char* str){
    char ch;
    int s=strlen(str);
    for(int i=0;i<s/2;i++){
        ch=str[i];
        str[i]=str[s-i-1];
        str[s-i-1]=ch;
    }
}
void trim(char* cargs[3]){
    if(cargs[1][0]=='-'){
        for(int i=0;i<strlen(cargs[1])-1;i++){
            cargs[1][i]=cargs[1][i+1];
        }
        cargs[1][strlen(cargs[1])-1]='\0';
    }
    if(cargs[2][0]=='-'){
        for(int i=0;i<strlen(cargs[2])-1;i++){
            cargs[2][i]=cargs[2][i+1];
        }
        cargs[2][strlen(cargs[2])-1]='\0';
    }
}
int orderNumbers(char* cargs[3]){
    //printf("%s,%s\n",cargs[1],cargs[2]);
    if(strlen(cargs[1])<strlen(cargs[2])){
        char* tmp=malloc(strlen(cargs[1]) + strlen(cargs[2]) + 1);
        strcpy(tmp,cargs[1]);
        strcpy(cargs[1],cargs[2]);
        strcpy(cargs[2],tmp);
        return 1;
    }else if(strlen(cargs[1])==strlen(cargs[2])){
        
        for(int i=0;i<strlen(cargs[1]);i++){
            if(cargs[1][i]<cargs[2][i]){
                char *tmp=malloc(strlen(cargs[1]) + strlen(cargs[2]) + 1);
                strcpy(tmp,cargs[1]);
                strcpy(cargs[1],cargs[2]);
                strcpy(cargs[2],tmp);
                return 1;
            }else if(cargs[1][i]>cargs[2][i]){
                return 0;
            }
        }
    }
    return 0;
}
void complete(char* cargs[3]){
    int p1 = strlen(cargs[1]), p2 = strlen(cargs[2]), isF1 = 0, isF2 = 0;
    //check is float
    for(int i=0;i<strlen(cargs[1]);i++){
        if(cargs[1][i]=='.'){
            p1=i;
            isF1=1;
            break;
        }
    }
    for(int i=0;i<strlen(cargs[2]);i++){
        if(cargs[2][i]=='.'){
            p2=i;
            isF2=1;
            break;
        }
    }
    //complete the part after decimal
        char s1[10000],s2[10000];
        strcpy(s1,cargs[1]);strcpy(s2,cargs[2]);
        if((strlen(cargs[1])-p1)>(strlen(cargs[2])-p2)){
            if(isF2==0){
                int s=strlen(cargs[1])-p1-1;
                char temp[s];temp[0]='.';
                int i=0;
                for(i=1;i<=strlen(cargs[1])-p1-1;i++){
                    temp[i]='0';
                }
                temp[i]='\0';
                strcat(s2,temp);
            }else{
                int i=0,s=(strlen(cargs[1])-p1-1)-(strlen(cargs[2])-p2-1);
                char temp[s];
                for(i=0;i<s;i++){
                    temp[i]='0';
                }
                temp[i]='\0';
                strcat(s2,temp);
            }
        }else if((strlen(cargs[1])-p1)<(strlen(cargs[2])-p2)){
            if(isF1==0){
                int s=(strlen(cargs[2])-p2-1);
                char temp[s];temp[0]='.';
                int i=0;
                for(i=1;i<=strlen(cargs[2])-p2-1;i++){
                    temp[i]='0';
                }
                temp[i]='\0'; 
                strcat(s1,temp);
            }else{
                int i=0,s=(strlen(cargs[2])-p2-1)-(strlen(cargs[1])-p1-1);
                char temp[s];
                for(i=0;i<s;i++){
                    temp[i]='0';
                }
                temp[i]='\0';
                strcat(s1,temp);
            }
        }else{

        }
        cargs[1] = s1;
        cargs[2] = s2;
}
int compare(char* s1, char* s2){
    //printf("-----------------------------%s,%s\n",s1,s2);
    char *a=malloc(strlen(s1)+1); char *b=malloc(strlen(s2)+1);
    strncpy(a,s1,strlen(s1)); strncpy(b,s2,strlen(s2));
    a[strlen(s1)]='\0';b[strlen(s2)]='\0';
    char* t[3]; t[1]=a;t[2]=b;
    complete(t);
    //printf("-----------------------------%s,%s\n",t[1],t[2]);
    if(strlen(t[1])>strlen(t[2])){
        free(a);free(b);
        return 1;
    }else if(strlen(t[1])<strlen(t[2])){
        free(a);free(b);
        return -1;
    }else{
        for(int i=0;i<strlen(t[1]);i++){
            if(t[1][i]>t[2][i]){
                free(a);free(b);
                return 1;
            }else if(t[1][i]<t[2][i]){
                free(a);free(b);
                return -1;
            }
        }
        free(a);free(b);
        return 0;
    }
}
int removePoint(char* cargs[3]){
    int b1=0,b2=0,i=0,j=0,count=0;
    for(i=0;i<strlen(cargs[1])-1;i++){
        if(cargs[1][i]=='.'){
            b1=1;
            count+=(strlen(cargs[1])-i-1);
        }
        if(b1==1){
            cargs[1][i]=cargs[1][i+1];
        }
    }
    if(b1==1){
        cargs[1][i]='\0';
    }
    for(j=0;j<strlen(cargs[2])-1;j++){
        if(cargs[2][j]=='.'){
            b2=1;
            count+=(strlen(cargs[2])-j-1);
        }
        if(b2==1){
            cargs[2][j]=cargs[2][j+1];
        }
    }
    if(b2==1){
        cargs[2][j]='\0';
    }
    return count;
}
char* addnew(char* n1,char* n2,char* ans){
    //printf("-------------------------%s+%s\n",n1,n2);
    char *s1;//=(char*)malloc(strlen(n1+1)*sizeof(char));
    char *s2;//=(char*)malloc(strlen(n2+1)*sizeof(char));
    int l1=(int)strlen(n1),l2=(int)strlen(n2);
        if(strlen(n1)>=strlen(n2)){
            s1=n1; s1[l1]='\0';
            s2=n2; s2[l2]='\0';
        }else{
            s2=n1; s2[l1]='\0';
            s1=n2; s1[l2]='\0';
        }
        //printf("------------------------- %s + %s\n",s1,s2);
        l1=(int)strlen(s1),l2=(int)strlen(s2);
        char a[l1+1];a[l1]='\0';
        int carr=0,p=0,i=0;//c->carry,p->present sum
        for(i=0;i<l2;i++){
            if(s1[l1-i-1]=='.'){a[l1-i-1]='.';continue;}
            int ch=s1[l1-i-1]+s2[l2-i-1]-96+carr;
            //printf("        ch = %d, i= %d\n",s1[l1-i-1],l2);
            if(ch<=9){
                a[l1-i-1]=ch+48;
                carr=0;
            }else{
                a[l1-i-1]=(ch%10)+48;
                carr=1;
            }
        }
        //printf("in func %s + %s = |%s|\n",s1,s2,a);
        for(i=l2;i<l1;i++){
            int ch = s1[l1-i-1]-48 + carr;
            if(ch<=9){
                a[l1-i-1]=ch+48;
                carr=0;
            }else{
                a[l1-i-1]=(ch%10)+48;
                carr=1;
            }
        }
        //printf("in func %s + %s = %s\n",s1,s2,a);
        //free(s1);free(s2);
        if(carr==1){
            char arr2[l1+1];
            strcpy(arr2,"1");
            strncat(arr2, a,l1);
            //printf("------------------------|%s|----- \n",arr2);
            strcpy(ans,arr2);
            return ans;
        }else{
            
            //ans=(char*)malloc(strlen(a));
            int l=strlen(a);
            // for(int i=0;i<l;i++){
            //     printf(" |%d| ",i);
            //     ans[i]=a[i];
            // }
            strcpy(ans,a);
            ans[l]='\0';
            //printf("------------------------|%s|--------- \n",ans);
            return ans;
        }
}
char* subnew(char *n1, char *n2, char* ans){
    char* s1=n1;
    char* s2=n2;
    //printf("---------------------------%s,%s\n",s1,s2);
    //l2 is smaller
    int l1 = strlen(s1), l2 = strlen(s2),d=l1-l2;
    char subs[l1+3];
    int carr=0,i,count=0;
    for(i=l2-1;i>=0;i--){
        if(s1[i+d]=='.'){subs[count]='.';count++;continue;}
        int a=s1[i+d]-s2[i]-carr;
        if(a>=0){
            carr=0;
        }else{
            a+=10;
            carr=1;
        }
        //printf("i=%d          %c-%c,sub=%d,carry=%d\n",i,s1[i],s2[i],a,carr);
        subs[count]=a+48;
        count++;
    }
    //printf("---------------------------%s,%s\n",s1,s2);
    //printf("%s\n",subs);
    for(i=l1-l2-1;i>=0;i--){
        int a=s1[i]-'0'-carr;
        if(a>=0){
            carr=0;
        }else{
            a+=10;
            carr=1;
        }
        subs[count]=a+'0';
        count++;
    }
    //printf("%s\n",subs);
    if(subs[count-1]=='0'&&count>1){
        int bo=1;
        if(strlen(subs)>=2){
            if(subs[count-2]=='.'){
                subs[count]='\0';
                bo=0;
            }
        }
        if(bo==1){
            subs[count-1]='\0';
        }
    }else{
        subs[count]='\0';
    }
    //printf("%s\n",subs);
    rev(subs);
    //printf("%s\n",subs);
    //ans=malloc(strlen(subs)+1);
    strcpy(ans,subs);
    ans[strlen(subs)]='\0';
    return ans;
}
char* mulByChar(int c1, char* st,char *curr){
    //printf("st = %s, curr = %s\n",st,curr);
    int l=strlen(st),mul=0,carry=0,count=0;
    char ans[l+2];
    //char* ptr=malloc(strlen(ans));
    for(int i=l-1;i>=0;i--){
        int c2= st[i]-'0';
        mul=c1*c2+carry;
        carry=mul/10;
        ans[count]=(mul%10)+'0';
        count++;
    }
    //printf("%s\n",ans);
    if(carry!=0){
        ans[count++]=carry+'0';
        ans[count]='\0';
    }else{
        ans[count]='\0';
    }
    //printf("--%s--%d,--%s|||\n",st,c1,ans);
    rev(ans);
    strcpy(curr,ans);
    //printf("---%s---\n",ptr);
    return curr;
}
char* mulnew(char* cargs[3], char *ans,char *h){
    int DecPlaces=removePoint(cargs);
    int shift=0;
    char* result=malloc((strlen(cargs[1])+strlen(cargs[2])+2)*sizeof(char));char res[2]="0\0";strcpy(result,res);
    
    for(int i=strlen(cargs[2])-1;i>=0;i--){
        char curr[strlen(cargs[2])+shift+10];
        curr[0]='\0';
        int c=cargs[2][i]-'0';
        //printf("cargs %s, curr %s\n",cargs[1],curr);
        mulByChar(c,cargs[1],curr);
        int l=strlen(curr),a=l;
        for(a=l;a<l+shift;a++){
            curr[a]='0';
        }
        curr[a]='\0';
        shift++;
        //tempargs[2]=curr;
        //printf("i = %d, curr = %s, result = %s\n",i,curr,result);
        addnew(result,curr,result);
        //printf("i = %d, curr = %s, result = %s\n",i,curr,result);
    }
    //printf("hey!!!\n");
    char final[strlen(result)+2];int i=0,b=0;
    for(i=0;b<strlen(result);i++){
        if((strlen(result)-i)==DecPlaces){
            final[i]='.';
        }else{
            final[i]=result[b];
            b++;
        }
    }
    //
    final[i]='\0';
    //printf("%d\n",i);
    //printf("|-|%s\n",final);
    //printf("%ld,%ld\n",strlen(final),sizeof(ans));
    int len=strlen(final);
    //ans[0]='\0';
    //ans[len-1]=final[len-1];
    //printf("het\n");
    // for(int k=0;k<len;k++){
    //     printf("|%d| ",k);
    //     ans[k]=final[k];
    // }
    //ans=malloc(100000);
    //printf("len = %d",len);
    strcpy(h,final);
    h[len]='\0';
    free(result);
    return h;
}
int findQ(char* a, char* d){
    int i=0;
    if(strlen(d)<strlen(a)){
        return 0;
    }else{
        char* res = malloc(max(strlen(a),strlen(d))+2);char zero[2]="0\0";strcpy(res,zero);
        for(int i=0;i<=10;i++){
            if(greater(d,res)==0){
                //printf("in greater--%d\n",i);
                subnew(res,a,res);
                //printf("res=%s\n",res);
                //printf("substr=%s,res=%s,,,,%s\n",args[1],res,args[2]);
                subnew(d,res,d);
                //printf("res=%s,,,ret=%d\n",res,i-1);
                free(res);
                return i-1;
            }else{
                addnew(res,a,res);
                //printf("i=%d,,,res=%s,div=%s\n",i,res,d);
            }
            
        }
    }
}
char* divnew(char* cargs[3], char* ans){
    removePointDiv(cargs);
    char* a = malloc(strlen(cargs[2]+1));
    strcpy(a,cargs[2]);
    char* d = malloc(max(strlen(cargs[1]),strlen(cargs[2]))+1000);
    strcpy(d,cargs[1]);
    char* q = malloc(max(strlen(cargs[1]),strlen(cargs[2]))+1000);char nul[0]="\0";strcpy(q,nul);
    int l=0,h=0,count=0,digitQ=0;
    char* curr = malloc(strlen(cargs[2])+2);
    curr=substring(l,h,d);
    int i=0,qD=0,countDecimal=0,boolCount=0;
    while(countDecimal<21){
        a=removeLead(a);
        qD=findQ(a,curr);
        //printf("            --qD=%d,DeciCount=%d\n",qD,countDecimal);
        //printf("            curr=%s\n",curr);
        h++;
        int len=strlen(q);
        q[len]=qD+48;q[len+1]='\0';
        if(h>=strlen(d)&&(allZero(curr)==1)){
            //printf("if\n");
            break;
        }else if(h>=strlen(d)){
            countDecimal++;//printf("incrementedi=%d\n",i);
            int len1=strlen(curr);
            curr[len1]='0';curr[len1+1]='\0';
            //printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\%s\n",curr);
            curr=removeLead(curr);
            //printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\%s\n",curr);
            //printf("elseif%s\n",curr);
        }else{
            //printf("hi%s\n",curr);
            int len1=strlen(curr);
            curr[len1]=d[h];curr[len1+1]='\0';
            //printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\%s\n",curr);
            curr=removeLead(curr);
            //printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\%s\n",curr);
            //printf("hi%s\n",curr);
        }
        i++;
    }
    if(countDecimal>=21){
        countDecimal--;
    }
    //printf("            quotient=%s,%d\n",q,countDecimal);
    //////////////////////////////
    //printf("start----------------------------------\n");
    char final[strlen(q)+3];
    int it=0,b=0;
    for(it=0;b<strlen(q);it++){
        //printf("%ld,%d\n",strlen(q),countDecimal);
        if((strlen(q)-it)==countDecimal){
            final[it]='.';
        }else{
            final[it]=q[b];
            b++;
        }
    }
    final[it]='\0';
    //printf("            final=%s\n",final);
    strcpy(q,final);
    q=removeLead(q);
    strcpy(ans,q);
    ans[strlen(q)]='\0';
    free(a);free(d);free(curr);
    return ans;
}
char* add_h(char *s1,char *s2){
    //printf("%s,%s\n",s1,s2);
    int sign=0;
    char* a[3];
    a[1]=s1;
    a[2]=s2;
    complete(a);
    int arg1=0,arg2=0;//0->positive 1->negative
    if(a[1][0]=='-'){arg1=1;}
    if(a[2][0]=='-'){arg2=1;}
    trim(a);
    char *temp,*ans=(char*)malloc((strlen(a[1])+strlen(a[2])+1)*sizeof(char));
    //printf("--------%ld-----------------\n",(strlen(a[1])+strlen(a[2])+1));
        if(arg1==0 && arg2==0){
            sign=0;
            temp=addnew(a[1],a[2],ans);
            
        }
        if(arg1==1 && arg2==0){
            if(orderNumbers(a)==1){
                sign=0;
            }else{
                
                sign=1;//answer is negative
            }
            temp=subnew(a[1],a[2],ans);
        }
        if(arg1==0 && arg2==1){
            //printf("01\n");
            if(orderNumbers(a)==1){
                sign=1;//answer  is negative
            }else{
                sign=0;//answer is positive
            }
            temp=subnew(a[1],a[2],ans);
        }
        if(arg1==1 && arg2==1){
            //printf("11\n");
            sign=1;//sign is negative
            temp=addnew(a[1],a[2],ans);
        }
        //removing zeros at the end
        int len=strlen(temp),hasPoint=-1,set=len,fset=1;
        for(int i=len-1;i>=0;i--){
            if(temp[i]=='0' && fset==1){
                set=i;
            }else{
                fset=0;
            }
            if(temp[i]=='.'){
                hasPoint=i;
                break;
            }
        }
        if(hasPoint!=-1){
            if(set==(hasPoint+1)){
                temp[hasPoint]='\0';
            }else if(set<len){
                temp[set]='\0';
            }else{

            }
        }
        if(allZero(temp)==1 && strlen(temp)>1){
            temp[1]='\0';
        }
        if(allZero(temp)==1){
            sign=0;
        }
        char *ret=(char*)malloc((strlen(temp)+2)*sizeof(char));
        if(sign==1){
            ret[0]='-';
            ret[1]='\0';
            strncat(ret,temp,strlen(temp));
            ret[strlen(temp)+1]='\0';
            //printf("addition = -%s\n",temp);
        }else{
            strncpy(ret,temp,strlen(temp));
            int l=strlen(temp);
            ret[l]='\0';
            //printf("addition = %s\n",temp);
        }
        free(ans);
        return ret;
    //printf("%s + %s = %s\n",a[1],a[2],temp);
}
char* sub_h(char *s1,char *s2){
    //printf("%s,%s\n",s1,s2);
    char *temp,*ans=(char*)malloc((strlen(s1)+strlen(s2)+1)*sizeof(char));
    int sign=0;
    char* a[3];
    a[1]=s1;
    a[2]=s2;
    complete(a);
    int arg1=0,arg2=0;//0->positive 1->negative
    if(a[1][0]=='-'){arg1=1;}
    if(a[2][0]=='-'){arg2=1;}
    trim(a);
    //printf("%s,%s\n",a[1],a[2]);
    if(arg1==0 && arg2==0){
            if(orderNumbers(a)==1){
                sign=1;
            }else{
                sign=0;
            }
            temp=subnew(a[1],a[2],ans);
        }//both are positive
        if(arg1==1 && arg2==0){
            sign=1;
            temp=addnew(a[1],a[2],ans);
        }
        if(arg1==0 && arg2==1){
            //printf("%s,%s\n",a[1],a[2]);
            sign=0;
            temp=addnew(a[1],a[2],ans);
        }
        if(arg1==1 && arg2==1){
            if(orderNumbers(a)==1){
                sign=0;
            }else{
                sign=1;
            }
            temp=subnew(a[1],a[2],ans);
        }
        //removing zeros at the end
        int len=strlen(temp),hasPoint=-1,set=len,fset=1;
        for(int i=len-1;i>=0;i--){
            if(temp[i]=='0' && fset==1){
                set=i;
            }else{
                fset=0;
            }
            if(temp[i]=='.'){
                hasPoint=i;
                break;
            }
        }
        if(hasPoint!=-1){
            if(set==(hasPoint+1)){
                temp[hasPoint]='\0';
            }else if(set<len){
                temp[set]='\0';
            }else{

            }
        }
        if(allZero(temp)==1 && strlen(temp)>1){
            temp[1]='\0';
        }
        //printf("temp is %s\n",temp);
        if(allZero(temp)==1){
            sign=0;
        }
        char *ret=(char*)malloc((strlen(temp)+2)*sizeof(char));
        if(sign==1){
            ret[0]='-';
            ret[1]='\0';
            strncat(ret,temp,strlen(temp));
            ret[strlen(temp)+1]='\0';
            //printf("substraction -%s\n",ans);
        }else{
            strncpy(ret,temp,strlen(temp));
            int l=strlen(temp);
            ret[l]='\0';
            //printf("subtraction %s\n",ans);
        }
        //free the ans
        free(ans);
        return ret;
}
char* mul_h(char *s1, char *s2){
    int leng=(strlen(s1)+strlen(s2)+1000);
    //printf("length =%d\n",leng);
    char *temp,*ans=(char*)malloc(leng*sizeof(char)),*h=malloc(100000);
    int sign=0;
    char* a[3];
    a[1]=malloc(100000);a[2]=malloc(100000);
    a[1]=s1;
    a[2]=s2;
    complete(a);
    int arg1=0,arg2=0;//0->positive 1->negative
    if(a[1][0]=='-'){arg1=1;}
    if(a[2][0]=='-'){arg2=1;}
    trim(a);
    if(arg1==0 && arg2==0){
            sign=0;
            temp=mulnew(a,ans,h);
        }//both are positive
        if(arg1==1 && arg2==0){
            sign=1;
            temp=mulnew(a,ans,h);
        }
        if(arg1==0 && arg2==1){
            sign=1;
            temp=mulnew(a,ans,h);
        }
        if(arg1==1 && arg2==1){
            sign=0;
            temp=mulnew(a,ans,h);
        }
        //mulNEW(cargs,ans);
        //printf("before %s\n",temp);
        //removing ending zeros
        int len=strlen(temp),hasPoint=-1,set=len,fset=1;
        for(int i=len-1;i>=0;i--){
            if(temp[i]=='0' && fset==1){
                set=i;
            }else{
                fset=0;
            }
            if(temp[i]=='.'){
                hasPoint=i;
                break;
            }
        }
        if(hasPoint!=-1){
            if(set==(hasPoint+1)){
                temp[hasPoint]='\0';
            }else if(set<len){
                temp[set]='\0';
            }else{

            }
        }
        if(allZero(temp)==1 && strlen(temp)>1){
            temp[1]='\0';
        }
        char *ret=(char*)malloc((strlen(temp)+2)*sizeof(char));
        //printf("temp is %s\n",temp);
        if(sign==1){
            ret[0]='-';
            ret[1]='\0';
            strncat(ret,temp,strlen(temp));
            ret[strlen(temp)+1]='\0';
            //printf("multiplication -%s\n",temp);
        }else{
            //int l=strlen(temp);
            // ret[strlen(temp)]='\0';
            // for(int i=0;i<l;i++){
            //     ret[i]=temp[i];
            // }
            strncpy(ret,temp,strlen(temp));
            int l=strlen(temp);
            ret[l]='\0';
        }
        free(ans);//freeing the malloc
        //printf("multiplication ret = %s\n",ret); 
        return ret;
}
char* div_h(char *s1, char *s2){
    char *temp,*ans=(char*)malloc((strlen(s1)+strlen(s2)+20)*sizeof(char));
    int sign=0;
    char* a[3];
    a[1]=s1;
    a[2]=s2;
    complete(a);
    int arg1=0,arg2=0;//0->positive 1->negative
    if(a[1][0]=='-'){arg1=1;}
    if(a[2][0]=='-'){arg2=1;}
    trim(a);
    if(arg1==0 && arg2==0){
            sign=0;
            temp=divnew(a,ans);
        }//both are positive
        if(arg1==1 && arg2==0){
            sign=1;
            temp=divnew(a,ans);
        }
        if(arg1==0 && arg2==1){
            sign=1;
            temp=divnew(a,ans);
        }
        if(arg1==1 && arg2==1){
            sign=0;
            temp=divnew(a,ans);
        }
        //removing zeros at the end
        int len=strlen(temp),hasPoint=-1,set=len,fset=1;
        for(int i=len-1;i>=0;i--){
            if(temp[i]=='0' && fset==1){
                set=i;
            }else{
                fset=0;
            }
            if(temp[i]=='.'){
                hasPoint=i;
                break;
            }
        }
        if(hasPoint!=-1){
            if(set==(hasPoint+1)){
                temp[hasPoint]='\0';
            }else if(set<len){
                temp[set]='\0';
            }else{

            }
        }
        if(allZero(temp)==1 && strlen(temp)>1){
            temp[1]='\0';
        }
        char *ret=(char*)malloc((strlen(temp)+2)*sizeof(char));
        if(sign==1){
            ret[0]='-';
            ret[1]='\0';
            strncat(ret,temp,strlen(temp));
            ret[strlen(temp)+1]='\0';
            //printf("division -%s\n",temp);
        }else{
            strncpy(ret,temp,strlen(temp));
            int l=strlen(temp);
            ret[l]='\0';
            //printf("division %s\n",temp);
        }
        free(ans);//freeing the mallo
        return ret;
}
int preprocess(char* s){
    int hasPoint=0,pIndex=-1,len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='.'){
            hasPoint=1;
            pIndex=i;
        }
    }
    //printf("%d\n",pIndex);
    if(hasPoint==1){
    if(len-1-pIndex>40){
        s[pIndex+41]='\0';
    }else if(len-1-pIndex<40){
        char t[42-len+pIndex];
        int i=0;
        for(i=0;i<(41-len+pIndex);i++){
            t[i]='0';
        }
        t[i]='\0';
        //printf("%s\n",t);
        strcat(s,t);
        //printf("%s\n",s);
    }else{

    }
    int j=0;
    for(j=pIndex;j<strlen(s)-1;j++){
        s[j]=s[j+1];
    }
    s[j]='\0';
    //printf("%s\n",s);
    }
    return pIndex;
}
void find(char *a, char *q,char *curr, int i){
    int len=strlen(a);
    a[len]='0';
    a[len+1]='\0';
    char *ans=malloc(1000);
    ans[0]='0';
    ans[1]='\0';
    
    //printf("a = %s    ans = %s\n",a,ans);
    //printf("done\n");
    int j=0;
    //printf("current a = %s\n",a);
    for(j=1;j<10;j++){
        a[strlen(a)-1]=j+48;
        //printf("current a = %s\n",a);
        mulByChar(j,a,ans);
        //printf("current ans = %s\n",ans);
        if(greaterS(ans,curr)==1){
            //printf("----------------------->break j is %d\n",j);
            j=j-1;
            
            break;
        }
    }
    if(j==10){
        j=9;
    }
    //printf("break j is %d,%c\n",j,j+48);
    a[strlen(a)-1]=j+48;
    //printf("final a = %s\n",a);
    mulByChar(j,a,ans);
    //printf("final ans = %s\n",ans);
    char temp[2];temp[0]=j+48;temp[1]='\0';
    //printf("temp = %s\n",temp);
    a=addnew(a,temp,a);
    //printf("final after addition a = %s\n",a);
    //printf("    curr,ans before sub %s,%s\n",curr,ans);
    removel(ans);
    removel(curr);
    subnew(curr,ans,curr);
    //printf("final curr = %s\n",curr);
    removel(curr);
    //printf("final curr = %s\n",curr);
    int blen=strlen(curr);
    curr[blen]='\0';
    //printf("final curr = %s\n",curr);
    q[i]=j+48;
    q[i+1]='\0';
    //printf("=======================q at this point %s\n",q);
    free(ans);
}
char* sqrtn(char *st,char *ans){
    //printf("len is %ld\n",strlen(st));
    char *s=malloc(10000);
    strncpy(s,st,strlen(st));
    s[strlen(st)]='\0';
    //printf(" -> %s, -> %s\n",s,st);
    //printf("--------------------------------------------------------------------------------\n");
    int p = preprocess(s);
    int k=0;
    if(p==-1){
        char t[41];
        p=strlen(s);
        int g=0;
        for(g=0;g<40;g++){
            t[g]='0';
        }
        t[g]='\0';
        strcat(s,t);
    }
    removel(s);
    //printf("%s\n",s);
    //printf("p = %d\n",p);
    char* a=malloc(1000);
    char* q=malloc(1000);
    char* curr=malloc(1000);
    a[0]='\0';
    
    
    if(p%2==0){
        curr=substring(0,1,s);
        k=2;
    }else{
        curr=substring(0,0,s);
        k=1;
    }
    //printf("a is %s\n",a);
    //printf("curr initial = %s\n",curr);
    int flen=strlen(s);
    //printf("k = %d, p = %d, len is %ld\n",k,p,strlen(s));
    int i=0;
    while(k<=flen+10){
        //printf("            i = %d\n",i);
        removel(curr);
        //printf("                                                curr = %s\n",curr);
        //printf("a is %s\n",a);
        find(a,q,curr,i);
        //printf("a is %s\n",a);
        //printf("        after find curr = %s\n",curr);
        // if(allZero(curr)&&k>=flen+1){
        //     break;
        // }
        //printf("    k=%d,len=%ld\n",k,strlen(q));
        if(k>=flen){
            break;
        }
        int clen=strlen(curr);
        curr[clen]=s[k++];
        curr[clen+1]=s[k++];
        curr[clen+2]='\0';
        //printf("        after find curr = %s\n",curr);
        i++;
    }
    q[strlen(q)]='\0';
    //printf("ans = %s , len is %ld\n",q,strlen(q));
    free(a); free(curr);free(s);
    ///////////////////////////////////////////////////
    int lenq=strlen(q);
    if(lenq>20){
        char final[lenq+2];
        int it=0,b=0;
        for(it=0;b<lenq;it++){
            if((lenq-it)==20){
                final[it]='.';
            }else{
                final[it]=q[b];
                b++;
            }
        }
        final[it]='\0';
        //printf("final=%s , lenf = %ld\n",final,strlen(final));
        strcpy(ans,final);
        ans[strlen(final)]='\0';
        //printf("ans=%s , lena = %ld\n",ans,strlen(ans));
    }else{
        char final[23];
        final[22]='\0';
        final[0]='0';
        final[1]='.';
        int it=0,b=21;
        for(it=lenq-1;it>=0;it--){
            final[b]=q[it];
            b--;
        }
        for(int jk=2;jk<=b;jk++){
            final[jk]='0';
        }
        //printf("final=%s , lenf = %ld\n",final,strlen(final));
        strcpy(ans,final);
        ans[strlen(final)]='\0';
        //printf("ans=%s , lena = %ld\n",ans,strlen(ans));
    }
    
    free(q);
    return ans;

}
char* sqrt_h(char *s){
    char *ans=malloc(10000);
    char *temp=sqrtn(s,ans);
    //printf("\nsquare root is %s\n",temp);
    //removing zeros at the end
        int len=strlen(temp),hasPoint=-1,set=len,fset=1;
        for(int i=len-1;i>=0;i--){
            if(temp[i]=='0' && fset==1){
                set=i;
            }else{
                fset=0;
            }
            if(temp[i]=='.'){
                hasPoint=i;
                break;
            }
        }
        if(hasPoint!=-1){
            if(set==(hasPoint+1)){
                temp[hasPoint]='\0';
            }else if(set<len){
                temp[set]='\0';
            }else{

            }
        }
        if(allZero(temp)==1 && strlen(temp)>1){
            temp[1]='\0';
        }
        //printf("\nsquare root is %s\n",temp);
        return temp;

}
// void sqrtnum(char* cargs[3]){
//     char* zero="0\0";
//     char* two="2\0";
//     cargs[2]=zero;
//     char *h=malloc(100000);char *l=malloc(100000);
//     strncpy(h,cargs[1],strlen(cargs[1]));
//     strncpy(l,cargs[2],strlen(cargs[2]));
//     char *mid=malloc(100000);
//     char *midS=malloc(100000);
//     char *t;
//     char* addargs[3];
//     char* sqrargs[3];
//     char* halfargs[3];

//     int i=0;

//     while(i<50){
//         i++;
//         printf("low = %s, high = %s\n",l,h);
//         //addargs[1]=l; addargs[2]=h;
//         //complete(addargs);
//         mid=add_h(l,h);
//         //printf("added = %s\n",mid);
//         //halfargs[1]=mid; halfargs[2]=two;
//         //complete(halfargs);
//         mid=div_h(mid,two);//divnew(halfargs,mid);
//         //printf("average = %s\n", mid);
//         sqrargs[1]=mid; sqrargs[2]=mid;
//         complete(sqrargs);
//         //printf("sqrargs are as follows %s,%s\n",sqrargs[1],sqrargs[2]);
//         midS=mul_h(mid,mid);//mulnew(sqrargs,t,midS);
//         //printf("sqr = %s\n",midS);
//         int com=compare(midS,cargs[1]);
//         //printf("the comparsion return %d\n",com);
//         if(com==1){
//             strncpy(h,mid,strlen(mid));
//             //printf("low = %s, high = %s\n",l,h);
//         }else if(com==-1){
//             strncpy(l,mid,strlen(mid));
//             //printf("low = %s, high = %s\n",l,h);
//         }else{
//             printf("ans=%s\n",mid);
//         }
//     }
// }

// int main(){

//     FILE *infile;//,*outfile; 
//     char c[100000];
//     infile = fopen ("input.txt", "r"); 
//         //outfile = fopen(argv[2], "w");
//     if (infile == NULL)
//     { 
//         fprintf(stderr, "\nError opening file\n"); 
//         exit (1); 
//     }
//     char* a[5];
//     while (fgets(c, sizeof c, infile)!= NULL){
        
//         if(c[strlen(c)-1]=='\n'){
//             c[strlen(c)-1]='\0';
//         }
//         char *ptr = strtok(c, " ,()");
//         int l=0;
//         while(ptr != NULL){
//             a[l]=ptr;
//             l++;
//             ptr = strtok(NULL, " ,()");
//         }
//         char *b1,*b2,*b3,*b4;
//         //b1=add_h(a[1],a[2]);
//         //b2=sub_h(a[1],a[2]);
//         //printf("%s,%s\n",a[1],a[3]);
//         //b3=mul_h(a[1],a[3]);
//         //b4=div_h(a[1],a[2]);
//         //b1=add_h(a[1],a[2]);
//         //char *ans=malloc(10000);
//         //b1=sqrt_h(a[1]);
//         //printf("\nanswer is %s\n",b1);
//         //printf("\nanswer is %s\n",b2);
//         //printf("\nanswer is %s\n",b3);
//         //printf("\nanswer is %s\n",b4);
//         // char res[10];
//         // mulByChar(3,"9000",res);printf("%s--\n",res);
//         // for(int i=0;i<5;i++){
//         //     printf("%s\n",a[i]);
//         // }
//         //printf("%s\n",command);
//         //parse(command,outfile);
//     }
//     // closing the file
//     //fclose (infile);
//     //fclose(outfile);
//     return 0;

// }
