// Name: Vansh Gandhi
// Project Name: (Prog 6)
// Due Date: (05/08/2024)
// I Certify that this program is my owm original work. I did not copy any part of this program from any other source.
// I further certify that I typed each and every line code in this program.


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

class BigInt
{
private:
    vector<char> v;
    BigInt fiboHelper(BigInt n, BigInt a = 0, BigInt b = 1);
public:
    BigInt();// done.
    BigInt(int);// done.
    BigInt(string);// 
    BigInt operator+(BigInt);// done.
    BigInt operator+(int);// done.
    BigInt operator-(BigInt);// done.
    BigInt operator-(int); //done.
    bool operator==(BigInt); // done.
    bool operator>=(BigInt);
    bool operator>(BigInt);
    bool operator<=(BigInt);
    BigInt operator*(BigInt);// done
    bool operator<(BigInt);// done
    BigInt operator/(BigInt);
    BigInt operator%(BigInt); //done.
    BigInt operator++(int);//post done.
    BigInt operator++( );//pre done.
    void print();// done.
    int size(); // done.
    BigInt fibo(); // calls fiboHelper
    BigInt fact();
    friend ostream& operator<<(ostream& out, BigInt b){
    if(b.size() <= 12){
    for(int t = b.size()-1; t>=0; t--){
        out<<int(b.v[t]);
    }
    }
    else{
        out<<int(b.v[(b.size()-1)])<<".";
        for(int t = b.size()-2; t>=b.size()-7; t--){
            out<<int(b.v[t]);
        }
        out<<"e"<<b.size()-1<<endl;
    }
    return out;
    }
     
    friend BigInt operator+ (int other, BigInt curr){
        BigInt oth = BigInt(other);
        BigInt ans = curr + oth;
        return ans;
    }
};
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
BigInt::BigInt(){
}


BigInt::BigInt(int num){
    if(num == 0){
        v.push_back(0);
    }
    else{
        while(num > 0){
            v.push_back(num % 10);
            num /= 10;
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

BigInt::BigInt(string str){
   for (int i = str.length() - 1; i >= 0; i--) 
        {
            v.push_back(int(str[i])-'0');
        }
}   

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
BigInt BigInt::operator+(BigInt other){
    BigInt ans;
    BigInt mt = (*this);
    if(mt.size() != other.size()){
        if(mt.size() < other.size()){
            while(mt.size() != other.size()){
                mt.v.push_back(0);
            }
        }
        else{
            while(mt.size() != other.size()){
                other.v.push_back(0);
            }
        }
        
    }
    
    int result, i = 0, carry_over = 0;

    while(i<other.size()){
        result = mt.v[i] + other.v[i] + carry_over;
        if (result>9){
            ans.v.push_back(result%10);     
            carry_over = 1;
            i++;
        }// This will store the number in reverse.
        else{
            ans.v.push_back(result);
            carry_over = 0;
            i++;
        }// This will store the number in reverse.
    }
    if(carry_over == 1){
        ans.v.push_back(1);
    }
   
    return ans;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

BigInt BigInt::operator-(BigInt other){
    BigInt ans;
    BigInt ab = (*this);
    
    while(ab.size() != other.size()){
        other.v.push_back(0);
    }
    int i = 0, res = 0;
    while(i<ab.size() && i<other.size()){
        if(v[i] < other.v[i]){
            ab.v[i+1] -= 1;
            res = (ab.v[i] + 10) - other.v[i];
            ans.v.push_back(res);
            i++;
        }
        else if(ab.v[i] > other.v[i]){
            ans.v.push_back(ab.v[i] - other.v[i]);
            i++;
        }  
        else{
            ans.v.push_back(0);
            i++;
        }
    }
    if(i<ab.v.size()){
        for(int j = i; j<ab.v.size(); j++){
            ans.v.push_back(ab.v[j]);
        }        
    }
    while(ans.v[ans.size()-1] == 0){
        ans.v.pop_back();
    }
    return ans;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

BigInt BigInt::operator+(int other){
    BigInt ans;
    BigInt sg = (*this);
    BigInt oth = BigInt(other);
    ans = sg + oth;
    return ans;

}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
BigInt BigInt::operator-(int other){
    BigInt result;
    BigInt jg = (*this);
    BigInt oth = BigInt(other);
    result = jg - oth;
    return result;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

bool BigInt::operator==(BigInt other){
    BigInt vg = (*this);
    if (vg.size() != other.size()) {
        return false;
    }
    for (int i = 0; i < vg.size(); i++) {
        if (vg.v[i] != other.v[i]) {
            return false;
        }
    }
    return true;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool BigInt::operator<(BigInt other){
    BigInt dp = (*this);
    if (dp.size() != other.size()) {
        return dp.size() < other.size();
    }

    for (int u = (dp.size() - 1); u >= 0; u--) {
        if (dp.v[u] != other.v[u]) {
            return dp.v[u] < other.v[u];
        }
    }
    return false;
}   
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
BigInt BigInt::operator*(BigInt other) {
    BigInt ans = 0;
    BigInt ag = (*this);
    if(ag < other){
    for (BigInt i = 0; i < ag; i = i + 1) {
        ans = ans + other;
    }
    }
    else if(other < ag){
     for (BigInt i = 0; i < other; i = i + 1) {
        ans = ans + ag;
    }   
    }
    else{
        for(BigInt i = 0; i < other; i = i + 1){
            ans = ans + ag;
        }
    }
    return ans;

}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool BigInt::operator>=(BigInt other){
    if (v.size() != other.v.size()) {
        return v.size() > other.v.size(); 
    }

    
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] != other.v[i]) {
            return v[i] > other.v[i]; 
        }
    }
    return true;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
BigInt BigInt::operator/(BigInt other){
    BigInt quotient;
    BigInt remainder = (*this);


    return quotient;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
BigInt BigInt::operator%(BigInt other){
    BigInt pm = (*this);
    BigInt quote = pm / other;
    return pm - (quote * other);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

BigInt BigInt::operator++(int other){
    BigInt sj = (*this);
    *this = *this + 1;
    return sj;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
BigInt BigInt::operator++(){
    *this = *this + 1;
    return *this;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int BigInt::size(){
    return v.size();
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
BigInt BigInt::fibo() {
  if (*this == BigInt(0)){
    return BigInt(0);
  }
  if (*this == BigInt(1)){
    return BigInt(1);
  }

  
  BigInt a = 0, b = 1, c;
  for (BigInt i = 2; i <= *this; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  return b;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool BigInt::operator<=(BigInt other) {
    BigInt ap = (*this);
    if (ap.size() != other.size()) {
        return ap.size() < other.size(); 
    }

    for (int i = ap.size() - 1; i >= 0; i--) {
        if (ap.v[i] != other.v[i]) {
            return ap.v[i] < other.v[i]; 
        }
    }
    return true;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool BigInt::operator>(BigInt other){
    BigInt kp = (*this);
    if (kp.size() != other.size()) {
        return kp.size() > other.size(); 
    }

    for (int i = kp.size() - 1; i >= 0; i--) {
        if (kp.v[i] != other.v[i]) {
            return kp.v[i] > other.v[i]; 
        }
    }
    return false;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
BigInt BigInt::fact() {
    
    BigInt uh = (*this);
    
    BigInt ans("1");
    
    while (uh > BigInt(1)) {
        ans = ans * uh;
        uh = uh - BigInt(1);
    }
    return ans;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void BigInt::print(){
    for(int t = v.size()-1; t>=0; t--){
        cout<<int(v[t]);
    }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
void testUnit()
{
int space = 10;
cout << "\a\nTestUnit:\n"<<flush;
system("whoami");
system("date");
// initialize variables
BigInt n1(25);
BigInt s1("25");
BigInt n2(1234);
BigInt s2("1234");
BigInt n3(n2);
BigInt fibo(12345);
BigInt fact(50);
BigInt imax = INT_MAX;
BigInt big("9223372036854775807");
// display variables
cout << "n1(int) :"<<setw(space)<<n1<<endl;
cout << "s1(str) :"<<setw(space)<<s1<<endl;
cout << "n2(int) :"<<setw(space)<<n2<<endl;
cout << "s2(str) :"<<setw(space)<<s2<<endl;
cout << "n3(n2) :"<<setw(space)<<n3<<endl;
cout << "fibo(12345):"<<setw(space)<<fibo<<endl;
cout << "fact(50) :"<<setw(space)<<fact<<endl;
cout << "imax :"<<setw(space)<<imax<<endl;
cout << "big :"<<setw(space)<<big<<endl;
cout << "big.print(): "; big.print(); cout << endl;
// cout << n2 << "/"<< n1<< " = "<< n2/n1 <<" rem "<<n2%n1<<endl;
cout << "fibo("<<fibo<<") = "<<fibo.fibo() << endl;
cout << "fact("<<fact<<") = "<<fact.fact() << endl;
cout << "10 + n1 = " << 10+n1 << endl;
cout << "n1 + 10 = " << n1+10 << endl;
cout << "(n1 == s1)? --> "<<((n1==s1)?"true":"false")<<endl;
cout << "n1++ = ? --> before:"<<n1++<<" after:"<<n1<<endl;
cout << "++s1 = ? --> before:"<<++s1<<" after:"<<s1<<endl;
cout << "s2 * big = ? --> "<< s2 * big<<endl;
cout << "big * s2 = ? --> "<< big * s2<<endl;
}




int main(){
    testUnit();

    return 0;
}