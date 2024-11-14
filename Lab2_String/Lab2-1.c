#include <stdio.h>
#include <string.h>

int indexSubString(const char *s, const char*t);
int main()
{
    const char *s = "abcabcdabcdeabcdefabcdefg";
    const char *t = "abcdeabcdefab";
    int position = indexSubString(s,t);
    if (position != -1){
    printf ("t的在s中的位置是%d\n", position);
    } else {
        printf ("t未在s中找到\n");
    }
}

int indexSubString(const char *s, const char *t)    //在字符串s中尝试匹配字符串t
{
    int lenS = strlen(s);
    int lenT = strlen(t);
    if (lenT==0) return 0;
    int i=0, j=0;

    while (i< lenS && j< lenT){
        if (s[i] == t[j]) {
            i++;
            j++;
        }  else{
            i = i - j+1;
            j = 0;
        }
    }
    
    if (j ==lenT) {
        return i - j;
    } else {
        return -1;
    }
}
