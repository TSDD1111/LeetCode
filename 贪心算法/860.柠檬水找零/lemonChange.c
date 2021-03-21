//计算收的的5、10美元的数量，用于找零即可，20美元优先用10美元找零，当5美元不够时直接返回false。

bool lemonadeChange(int* bills, int billsSize){
    int five = 0, ten = 0;
    for(int i = 0; i < billsSize; i++){
        if(bills[i] == 5){
            five++;
        }
        else if(bills[i] == 10){
            five--;
            ten++;
        }
        else{
            if(ten > 0){
                ten--;
                five--;
            }
            else{
                five -=3;
            }
        }
        if(five < 0){
            return false;
        }
    }
    return five >= 0 && ten >= 0;
}
