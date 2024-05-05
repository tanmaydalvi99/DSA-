#include<iostream> 
#include<string.h> 
#include<stdlib.h> 
using namespace std; 

class HashFunction 
{ 
    typedef struct hash 
    { 
        long key; 
        char name[10]; 
        int chain; 
    }hash; 

    hash h[10]; 
	
public: 
    HashFunction(); 
    void insert(); 
    void display(); 
    int find(long); 
    void Delete(long); 
}; 

HashFunction::HashFunction() 
{ 
    int i; 
    for(i=0;i<10;i++) 
    { 
        h[i].key=-1; 
        strcpy(h[i].name,"NULL"); 
        h[i].chain=-1; 
    } 
} 

void HashFunction::Delete(long k) 
{ 
    int index=find(k); 
    if(index==-1) 
    { 
        cout<<"\n\tKey Not Found"; 
    } 
    else  
    { 
        h[index].key=-1; 
        strcpy(h[index].name,"NULL"); 
        cout<<"\n\tKey is Deleted"; 
    } 
} 

int HashFunction::find(long k) 
{ 
    int hi,i; 
    hi=k%10; 
    if(hi!=-1 && k==h[hi].key) 
    { 
        cout<<"\n\t"<<h[hi].key<<" is Found at "<<hi<<" Location With Name "<<h[hi].name; 
        return hi; 
    } 
    else if(hi!=-1) 
    { 
        for(i=hi+1;i!=hi;i=(i+1)%10) 
        { 
            if(k==h[i].key) 
            { 
                cout<<"\n\t"<<h[i].key<<" is Found at "<<i<<" Location With Name "<<h[i].name; 
                return i; 
            } 
        } 
    } 
    else 
    { 
        return -1; 
    } 
} 

void HashFunction::display() 
{ 
    int i; 
    cout<<"\n\t\tKey\t\tName\t\tChain"; 
    for(i=0;i<10;i++) 
    { 
        cout<<"\n\th["<<i<<"]\t"<<h[i].key<<"\t\t"<<h[i].name<<"\t\t"<<h[i].chain; 
    } 
} 

void HashFunction::insert() 
{ 
    char ans,n[10]; 
    long k; 
    int hi,cnt=0,i,ch,preind; 
    do 
    { 
        if(cnt>=10) 
        { 
            cout<<"\n\tHash Table is FULL"; 
            break; 
        } 
        cout<<"\n\tEnter a Telephone No: "; 
        cin>>k; 
        cout<<"\n\tEnter a Client Name: "; 
        cin>>n; 
        hi=k%10;
        if(h[hi].key==-1) 
        { 
            h[hi].key=k; 
            strcpy(h[hi].name,n); 
        } 
        else 
        { 
            cout<<"\n Collision occurs ..... use collision resolution strategy"; 
            ch=h[hi].chain; 
            if(ch==-1) 
            { 
                preind=hi; 
                for(i=0;i<10;i++) 
                { 
                    if(h[hi%10].key==-1) 
                    { 
                        h[hi%10].key=k; 
                        strcpy(h[hi%10].name,n); 
                        h[preind].chain=hi%10; 
                        break; 
                    } 
                    hi++; 
                } 
            } 
            else 
            { 
                while((h[ch].key!=-1) && (h[ch].chain!=-1)) 
                    ch=h[ch].chain; 
                for(i=0;i<10;i++) 
                { 
                    if(h[hi%10].key==-1) 
                    { 
                        h[hi%10].key=k; 
                        strcpy(h[hi%10].name,n); 
                        h[ch].chain=hi%10; 
                        break; 
                    } 
                    hi++; 
                } 
            } 
        } 
        cnt++; 
        cout<<"\n\t. .... Do You Want to Insert More Key: "; 
        cin>>ans; 
    }while(ans=='y'||ans=='Y'); 
} 

int main() 
{ 
    long k; 
    int ch,index; 
    char ans; 
    HashFunction obj; 
    do 
    { 
        cout<<"\n\t***** Dictionary (ADT) *****"; 
        cout<<"\n\t1. Insert\n\t2. Display\n\t3. Find\n\t4. Delete\n\t5. Exit"; 
        cout<<"\n\t...... Enter Your Choice: "; 
        cin>>ch; 
        switch(ch) 
        { 
            case 1: 
                obj.insert(); 
                break; 
            case 2: 
                obj.display(); 
                break; 
            case 3: 
                cout<<"\n\tEnter a Key Which You Want to Search: "; 
                cin>>k; 
                index=obj.find(k); 
                if(index==-1) 
                { 
                    cout<<"\n\tKey Not Found"; 
                } 
                break; 
            case 4: 
                cout<<"\n\tEnter a Key Which You Want to Delete: "; 
                cin>>k; 
                obj.Delete(k); 
                break; 
            case 5: 
                break; 
        } 
        cout<<"\n\t...... Do You Want to Continue in Main Menu: "; 
        cin>>ans; 
    }while(ans=='y'||ans=='Y'); 
    return 0;
} 
