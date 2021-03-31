//可以考虑建个哈希表来存储。

int getValue(char s){
    switch(s){
        case 'I':return 1;
        case 'V':return 5;
        case 'X':return 10;
        case 'L':return 50;
        case 'C':return 100;
        case 'D':return 500;
        case 'M':return 1000;
        default :return 0;
    }
}

int romanToInt(char * s){
    int sum = 0;
    int length = strlen(s);
    for(int i = 0; i < length; i++){
        if(i + 1 < length && getValue(s[i]) < getValue(s[i + 1])){
            sum -= getValue(s[i]);
        }
        else{
            sum += getValue(s[i]);
        }
    }
    return sum;
}
