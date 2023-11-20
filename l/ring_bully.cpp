/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;
class node  {
    public:
  int id;
  bool alive;
  node(int id) {
    this->id = id;
    alive = true;
  }
  };

class election
{
    public:
    vector<node>v;
    int n;
    void input()
    {
        
        cout<<"Enter number of Nodes : ";
        cin>>n;
        for(int i=0; i<n; i++)
        {
            int id;
            cout<<"Enter ID of "<<i+1<<" Node : ";
            cin>>id;
            node obj(id);
            v.push_back(obj);
        }
    }
    void ring()
    {
        cout<<"****************************************************************************************************"<<endl;
        cout<<"Ring algorithm :"<<endl;
        int max_id_node=0;
        for(int i=0; i<n; i++)
        {
            if(v[i].id>v[max_id_node].id)
            {
                max_id_node=i;
            }
        }
        cout << "Node " << max_id_node+1 << " is the current Coordinator" << endl;
        usleep(500000);
        cout << "Node " << max_id_node+1 << " failed." << endl;
        usleep(500000);
        v[max_id_node].alive=false;
    
    
        int detector=max_id_node;
        while(detector==max_id_node)
        {
            detector= rand() % (v.size());
        }
        cout<<"\nNode " << detector + 1 << " detected failure.\n"<< endl;
             
        usleep(500000);
        cout << "\nNode " << detector + 1 << "starts the election.\n"<< endl;
        usleep(500000);
        int curr=(detector+1)%(v.size());
        vector<int>id_seq;
        id_seq.push_back(v[detector].id);
        int prev=detector;
        int count=0;
        while(curr!=detector+1 || count==0)
        {
            
            cout<<"Message passed from node "<<prev+1<<" to "<< curr+1 <<" : [ ";
            for(auto i:id_seq)
            {
                cout<<i<<" ";
            }
            cout<<"]"<<endl;
            usleep(500000);
            if(v[curr].alive==true)
            {
                id_seq.push_back(v[curr].id);
            }
            
            prev=curr;
            curr++;
            curr=curr%(v.size());
            count++;
            
        }
        cout<<"Now, node "<<detector+1<<" who initiated the election process has recieved its message back containing all the ids of the alive nodes"<<endl;
        usleep(500000);
        cout<<"Node "<<detector+1<<" detects highest id number from list and elects it as the new coordinator."<<endl;
        usleep(500000);
        int max_id=*max_element (id_seq.begin(), id_seq.end());
        int coord=0;
        for(int i=0; i<n; i++)
        {
            if(v[i].id==max_id)
            {
                coord=i;
                break;
            }
        }
        cout<<"Node "<<coord+1<<" is the new coordinator"<<endl;
        usleep(500000);
        cout<<"****************************************************************************************************"<<endl;

    
    }
    void  bully()
    {
        cout<<"****************************************************************************************************"<<endl;
        cout<<"Bully algorithm :"<<endl;
        int max_id_node=0;
        for(int i=0; i<n; i++)
        {
            if(v[i].id>v[max_id_node].id)
            {
                max_id_node=i;
            }
        }
        cout << "Node " << max_id_node+1 << " is the current Coordinator" << endl;
        usleep(500000);
        cout << "Node " << max_id_node+1 << " failed." << endl;
        usleep(500000);
        v[max_id_node].alive=false;
    
    
        int detector=max_id_node;
        while(detector==max_id_node)
        {
            int j=rand();
            detector= j % (v.size());
        }
        cout<<"\nNode " << detector + 1 << " detected failure.\n"<< endl;
             
        usleep(500000);
        cout << "\nNode " << detector + 1 << "starts the election.\n"<< endl;
        usleep(500000); 
        int curr=detector;
        int count=1;
        while(count!=0)
        {
            for(int i=0; i<n; i++)
            {
                if(v[i].id>v[curr].id)
                {
                    cout<<"\nNode " << curr + 1 << " sends election message to node "<<i+1<< endl;
                    usleep(500000);
                }
            }
            int mini=INT_MAX;
            int mini_ind=0;
            count=0;
            for(int i=0; i<n; i++)
            {
                if(v[i].id>v[curr].id && v[i].alive==true)
                {
                    cout<<"\nNode " << i + 1 << " sends OK message to node "<<curr +1<< endl;
                    usleep(500000);
                    if(v[i].id<mini)
                    {
                        mini=v[i].id;
                        mini_ind=i;
                      
                    }
                    
                    
                    count++;
                    
                }
              
            }
            curr=mini_ind;
            
        }
         cout<<"As Node "<<curr+1<<" doesn't get any more OK responses from the other nodes to its Election message, It declares itselves as new coordinator"<<endl;
         cout<<"Node "<<curr+1<<" is the new coordinator"<<endl;
         cout<<"****************************************************************************************************"<<endl;
        usleep(500000);
        
        
        
    }
    
};
    


int main()
{
    srand (time (0));
    election e;
    e.input();
    e.ring();
    e.bully();

    return 0;
}
