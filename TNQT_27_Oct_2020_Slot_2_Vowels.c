/*Question
Take a single line text message from user. Separate the vowels from the
text. Find the repeating occurrences of vowels from the text message.
Display count of which vowel has repeated how many times.
Display a new Text message by removing the vowel characters as output
Display the output in exact format shown below in example, after
displaying count of characters on next lines display the new text message
on next line
"Hii wlcm" is the new text message
If text message entered by user does not contain any vowels then display
O as output
If text message entered by user contain any numeric value then display O
as output
If User enters blank or empty text message display "INVALID INPUT as
output. Message INVALID INPUT" is case sensitive Display it in exact
format given */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char str[100];
    scanf("%[^\n]%*c",str);
    int a_count=0, e_count=0, i_count=0, o_count=0, u_count=0;
    if(str[0] == ' ')
        printf("INVALID INPUT");
    else{
        for(int i=0;i<strlen(str);i++){
            if(str[i]=='a' || str[i]=='A') a_count++;
            if(str[i]=='e' || str[i]=='E') e_count++;
            if(str[i]=='i' || str[i]=='I') i_count++;
            if(str[i]=='o' || str[i]=='O') o_count++;
            if(str[i]=='u' || str[i]=='U') u_count++;
         }
         if(a_count==0 && e_count==0 && i_count==0 && o_count==0 && u_count==0)
            printf("0");
        else{
            printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",a_count,e_count,i_count,o_count,u_count);
            for(int i=0;i<strlen(str);i++)
                if(!(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'))
                    printf("%c",str[i]);
        }
    }
    return 0;
}
