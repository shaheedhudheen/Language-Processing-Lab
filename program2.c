//WAP to genarate lexical analizer

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
 int isIdentifier (char a[])

{



int flag, i=1;


if(isalpha(a[0]))

flag=1;

else

return 0;

while(a[i]!='\0')

{

if(!isdigit(a[i])&&!isalpha(a[i]))

{

flag=0;

break;

}

i++;

}

if(flag==1)

 return 1;
}
int isKeyword(char buffer[]){
char keywords[32][10] = {"auto","break","case","char","const","continue","default",
"do","double","else","enum","extern","float","for","goto",
"if","int","long","register","return","short","signed",
"sizeof","static","struct","switch","typedef","union",
"unsigned","void","volatile","while"};
int i, flag = 0;
for(i = 0; i < 32; ++i){
if(strcmp(keywords[i], buffer) == 0){
flag = 1;
break;
}
}
return flag;
}
 
int main(){
char ch,path[100], buffer[15], operators[] = "+-*/%=";
FILE *fp;
int i,j=0;
 printf("Enter source file path: ");
    scanf("%s", path);
	fp = fopen(path, "r");
if(fp == NULL){
printf("error while opening the file\n");
exit(0);
}
while((ch = fgetc(fp)) != EOF){
   for(i = 0; i < 6; ++i){
   if(ch == operators[i])
   printf("%c is operator\n", ch);
   }
  
   if(isalnum(ch)){
   buffer[j++] = ch;
   }
   else if((ch == ' ' || ch == '\n') && (j != 0)){
   buffer[j] = '\0';
   j = 0;
     
   if(isKeyword(buffer) == 1){
   		printf("%s is keyword\n", buffer);
   		continue;
   }
   if(isIdentifier(buffer)==1){
   		printf("%s is identifier\n" , buffer);
   		continue;
   }
   if(isIdentifier(buffer)==0){
   			printf("%s is not identifier\n" , buffer);
   		continue;
   }
}
   	
   	
   
  
}
fclose(fp);
return 0;
}