//利用贪心和单调栈来排除重复字母
//将每一个字母依次压入栈中，每次判断的字母都与栈顶字母判断，
//若栈顶字母大，且该字母剩余数量不为0，则弹出继续判断，
//直至判断字母最小或者栈顶字母剩余数量为0。
//依次判断，直至最后一个，即可返回结果

char * removeDuplicateLetters(char * s){
    //分别存放每个字母的数量和该字母是否已经在栈中
    int num[26], has[26];
    memset(num, 0, sizeof(num));
    memset(has, 0, sizeof(has));
    //计算每个字母的数量
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        num[s[i] - 'a']++;
    }
    //判断每一个字母并压入栈
    char* m = malloc(sizeof(char) * 27);
    int mTop = 0;
    for(int i = 0; i < n; i++){
        //如果该字母不在栈中
        if(!has[s[i] - 'a']){
            //栈中已经有字母，且栈顶字母比判断字母大
            while(mTop > 0 && m[mTop - 1] > s[i]){
                //栈顶字母剩余数量大于0
                if(num[m[mTop - 1] - 'a'] > 0){
                    //栈顶字母弹出，即栈顶指针前移一位，并设置栈顶字母不在栈中
                    has[m[--mTop] - 'a'] = 0;
                }
                else{
                    break;
                }
            }
            //否则将该字母压入栈中，记为存在且栈顶指针后移一位
            has[s[i] - 'a'] = 1;
            m[mTop++] = s[i];
        }
        //对应字母的数量减一
        num[s[i] - 'a']--;
    }
    //末尾加上'\0'表示结束
    m[mTop] = '\0';
    return m;
}
