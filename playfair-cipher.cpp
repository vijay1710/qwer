#include<iostream>
#include<vector>
using namespace std;

const char encoder[5][5]={{'V','I','J','A','Y'},        
                    {'B','C','D','E','F'},
                    {'G','H','k','L','M'},
                    {'N','O','P','Q','R'},
                    {'S','T','U','W','X'}};

void getPosition(char,int&,int&);
void sameColoumn(vector<char>&,int,int,int);
void sameRow(vector<char>&,int,int,int);
void diffColoumn(vector<char>&,int,int,int,int);
void declutter(vector<char>&,vector<char>&);
void getInput(vector<char>&);              
vector<char> encipher(vector<char>&);
void print(vector<char>&);

void getInput(vector<char>& msg){
    char c;
    cout<<"Enter the message:\n";
    while(1){
        c=getchar();
        if (c=='j')
            c='I';
        else if(c>=97 && c<=122)
            c-=32;
        else if(c==' ')
            continue;
        else if(c=='\n')
            break;
        else if(c=='J')
            c='I';
        else if(!(c>=65 && c<=90))
            continue;
        msg.push_back(c);
    }
    return;
}

void declutter(vector<char>& msg, vector<char>& msgx){
    for(int i=0;i<msg.size();i++){
        if(msg[i]==msg[i+1]){
            msgx.push_back(msg[i]);
            msgx.push_back('X');
        }
        else{
            msgx.push_back(msg[i]);
        }
    }
    if(msgx.size()%2)
        msgx.push_back('X');
    return;
}

void print(vector<char>& msg){
    for(int i=0;i<msg.size();i++){
        cout<<msg[i];
    }
    cout<<"\n";
    return;
}

void getPosition(char ch,int& row, int& col){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(encoder[i][j]==ch){
                row=i;
                col=j;
            }
        }
    }
    return;
}

vector<char> encipher(vector<char>& msgx){
    vector<char> cipher;
    int r1,r2,c1,c2;
    int i=0;
    while(i<msgx.size()){
        getPosition(msgx[i],r1,c1);
        i++;
        getPosition(msgx[i],r2,c2);
        if(r1==r2)
            sameRow(cipher,r1,c1,c2);
        else if(c1==c2)
            sameColoumn(cipher,c1,r1,r2);
        else
            diffColoumn(cipher,r1,r2,c1,c2);  
        i++;      
    }
    return cipher;

}

void sameRow(vector<char>& cipher,int r1,int c1,int c2){
    cipher.push_back(encoder[r1][(c1+1)%5]);
    cipher.push_back(encoder[r1][(c2+1)%5]);
    return;
}

void sameColoumn(vector<char>& cipher,int c1,int r1,int r2){
    cipher.push_back(encoder[(r1+1)%5][c1]);
    cipher.push_back(encoder[(r2+1)%5][c1]);
    return;
}

void diffColoumn(vector<char>& cipher,int r1,int r2,int c1,int c2){
    cipher.push_back(encoder[r1][c2]);
    cipher.push_back(encoder[r2][c1]);
    return;
}


int main(){
    vector<char> msg;
    vector<char> msgx;
    vector<char> cipher;
    getInput(msg);
    print(msg);
    declutter(msg,msgx);
    print(msgx);
    cipher = encipher(msgx);
    cout<<"Cipher Text: ";
    print(cipher);
    return 0;
}
