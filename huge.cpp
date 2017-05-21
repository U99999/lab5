#include<iostream>
#include<cstring>
#define digit 40
using namespace std;
class HugeInt;
istream &operator >>(istream & in, HugeInt & x);
ostream &operator <<(ostream & out, HugeInt & result);
HugeInt operator +(HugeInt x,HugeInt y );
HugeInt operator -(HugeInt x,HugeInt y );
class HugeInt{
        public:
	 HugeInt(){};
        HugeInt(long y){
        for(int i=0;i<digit;++i)
         huge[i]=0;
        for(int i=0;y!=0;++i){
        huge[i]=y%10;
        y/=10;
        }
        }
        HugeInt(string z){
        int len=z.size();
        for(int i=0;i<digit;++i)
         huge[i]=0;
        for(int i=len-1;i>=0;--i)
        huge[len-i-1]=z[i]-'0';
        }
        friend istream &operator >>(istream & in, HugeInt & x);
       friend  HugeInt operator +(HugeInt x,HugeInt y );
        friend  HugeInt operator -(HugeInt x,HugeInt y );
       friend ostream &operator <<(ostream & out, HugeInt & result);
	 private:
        int huge[digit];
        int number;
        };

	istream &operator >>(istream & in, HugeInt & x){
        in>>x.number;
        for(int i=0;i<digit;++i)
        x.huge[i]=0;
        for(int i=0;x.number!=0;++i){
        x.huge[i]=x.number%10;
        x.number/=10;
        }
        return in;
        }
        HugeInt operator +(HugeInt x,HugeInt y ){
        HugeInt result;
        for(int i=0;i<digit;++i){
        result.huge[i]=x.huge[i]+y.huge[i];
 	
	}
        for(int j=0;j<digit;++j){
        if(result.huge[j]>=10){
        result.huge[j]=result.huge[j]-10;
        result.huge[j+1]=result.huge[j+1]+1;
	 }
        }
        return result;
        }
         HugeInt operator -(HugeInt x,HugeInt y ){
        HugeInt result;
        for(int i=0;i<digit;++i){
        if(x.huge[i]<y.huge[i]){
	
        x.huge[i]+=10;
        x.huge[i+1]-=1;
        }
        result.huge[i]=x.huge[i]-y.huge[i];
        }
        return result;
        }
	ostream &operator <<(ostream & out, HugeInt & result){
	int zero_len=0;
	for(int i=digit-1;i>=0;--i){
	if(result.huge[i]==0)
	++zero_len;
	else
	break;
	}
	for(int i=digit-zero_len-1;i>=0;--i)
	out<< result.huge[i];
	return out;
	}
