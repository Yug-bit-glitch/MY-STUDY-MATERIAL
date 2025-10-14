int jump(int* nums, int numsSize) {
    int jump=0;
    int current=0;
    int max=0;
    for(int i=0;i<numsSize-1;i++){
        if((nums[i]+i)>max){
            max=nums[i]+i;
        }
        if(i==current){
            jump++;
            current=max;
            if(current>=(numsSize-1)){
                break;
            }
        }
    }
    return jump;
}
