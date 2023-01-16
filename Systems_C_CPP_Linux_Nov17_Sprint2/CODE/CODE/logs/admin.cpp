#include<iostream>
#include<string.h>
#include"admin.h"
#include"logger.h"
using namespace std;

void userName(char name[]){
        int flag=0;
        for(int i=0;name[i]='\0';i++){
                if(name == NULL &&(( name[i]<65 || name[i]>90)&& ( name[i]<97 || name[i]>122)))
                {
                        flag=1;
                        break;
                }
        }
        if(flag==1)
               LOG_INFO("Enter valid name");
        else
                LOG_INFO("\nEntered name is: %s",name);
}

void userPswd(char pswd[])
{
        int digi,lower,upper,splchar;
        digi=lower=upper=splchar=0;
        for(int i=0;pswd[i]!='\0';i++)
        {
                if(isdigit(pswd[i]))
                        digi++;
                if(islower(pswd[i]))
                        lower++;
                if(isupper(pswd[i]))
                        upper++;
                if(pswd[i]=='@')
                        splchar++;
        }
        if(digi!=0 && lower!=0 && upper!=0 && splchar)
                LOG_INFO("\nEntered password is in correct format.. %s",pswd);
        else
                LOG_INFO("Please enter in a correct format");
}