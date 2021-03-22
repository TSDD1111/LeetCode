//判断两个字符是否相等，？为通配符
bool charMatch(char v, char u){
    return v == u || u == '?';
}

bool isMatch(char * s, char * p){
    //获取两个字符串的长度
    int sLength = strlen(s), pLength = strlen(p);
    //判断p的最后一个字符是否为*且是否与s相等
    while(sLength && pLength && p[pLength - 1] != '*'){
        if(charMatch(s[sLength - 1], p[pLength - 1])){
            sLength--;
            pLength--;
        }
        else{
            return false;
        }
    }
    //p若为空，s只能为空
    if(pLength == 0){
        return sLength == 0;
    }
    //暴力寻找p每个*之间的字符串是否在s中出现
    int sIndex = 0, pIndex = 0;           //s、p的当前下标
    int sRecord = -1, pRecord = -1;       //记录每次遇到*时开始的位置
    while(pIndex < pLength && sIndex < sLength){
        //p当前为*，则p前移一位，record记录反悔选择的地方,第一次从sIndex匹配，不成功从sIndex+1开始匹配
        //且如果p的第一位不为*，则没有重新选择的机会
        if(p[pIndex] == '*'){
            pIndex++;
            pRecord = pIndex;
            sRecord = sIndex;
        }
        //比较两个字符是否相同，相同各前移一位
        else if(charMatch(s[sIndex], p[pIndex])){
            pIndex++;
            sIndex++;
        }
        //如果sRecord等于-1，说明p的首字符不为*，否则可以退回去重新判断
        //重点!!可以退回去判断
        else if(sRecord != -1 && sRecord < sLength - 1){
            sRecord++;
            sIndex = sRecord;
            pIndex = pRecord;
        }
        else{
            return false;
        }
    }
    //判断p剩余的字符是否为*
    for(int i = pIndex; i < pLength; i++){
        if(p[i] != '*'){
            return false;
        }
    }
    return true;
}
