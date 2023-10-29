int judge(char *ins){
    int i,n1,n2,n3,P,T;
    n1=n2=n3=0;
    P=T=0;
    for(i=0;ins[i]!='\0';i++){
        switch (ins[i]){
            case 'P':
                if(P) return 0;
                else P=1;
                break;
            case 'T':
                if(!P||T)return 0;
                else T=1;
                break;
            case 'A':
                if(!P)n1++;
                else if(!T)n2++;
                else n3++;
                break;
            default:
                return 0;
                break;
        }
    }
    if(!(P&&T)||!n2) return 0;
    if((n1*n2)==n3) return 1;
    else return 0;
}