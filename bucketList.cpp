// Name: Vansh Gandhi
// Project Name: (Prog 5)
// Due Date: (04/22/2024)
// I Certify that this program is my owm original work. I did not copy any part of this program from any other source.
// I further certify that I typed each and every line code in this program.
#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <cstdlib>
using namespace std;

int globalSwapCount = 0;

class Bucket
{
private:
    vector<int> v;

public:
    Bucket();
    void generate(int size, int min, int max);  //done
    void sort();  //done
    int size();  //done
    int atIndex(int index);  //done
    int merge(Bucket b);
};
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Bucket::Bucket(){

}
void Bucket::sort(){
    int size = v.size();
    
    for(int i = 0; i <(size)-1; i++){
        for(int j = 0; j <(size)-1-i; j++){
            if(v[j] > v[j+1]){
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                globalSwapCount++;  
            }
        }
    }    
}

int Bucket::size(){
    return v.size();
}

int Bucket::atIndex(int index){
        return v[index];
  
}

void Bucket::generate(int size, int min, int max){

	for (int i = 0; i < size; i++){
	    v.push_back(rand() % (max-min+1) + min) ;
	}

	
}

int Bucket::merge(Bucket b){
    vector<int> mer;
    int p1 = 0;
    int p2 = 0;
    while(p1<v.size() && p2<b.size()){

        if (v[p1] < b.atIndex(p2)){         // If the element in v vector on the index p1 is less it will be added to the merge vetor.
            mer.push_back(v[p1]);
            p1 += 1;
        }
        else if(v[p1] == b.atIndex(p2))   {         // If the element in bucket b vector on the index p2 is less it will be added to the merge vetor.
            mer.push_back(b.atIndex(p2));
            mer.push_back(v[p1]);
            p2 += 1;
            p1 += 1;
        }
        else{
            mer.push_back(b.atIndex(p2));           // if both are equal then both the values are added to the merge function.
            p2 += 1;
        }
    }
    
    if(p1<v.size()){                            // if the vector of bucket b is already added then all the remaining part of the vector v will be added to the merge function.
        for(int i = p1; i < v.size(); i++){
            mer.push_back(v[i]);
        }
    }
    else if(p2<b.size()){
        for(int i = p2; i < b.size(); i++){     // if the vector v is already finished then the remaining part of the vector of Bucket B will be added.
            mer.push_back(b.atIndex(i));
        }
    }
    v = mer;
    return v.size();
}

    
















//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------






int main(int argc, char *argv[])
{
    srand(time(0));
    int bucketCount = stoi(argv[1]);
    int bucketSize = stoi(argv[2]);
    int bucketMin = stoi(argv[3]);
    int bucketMax = stoi(argv[4]);
    cout << "Bucket Count:"<<bucketCount<<endl;
    cout << "Bucket Size:"<<bucketSize<<endl;
    cout << "Bucket Min Value:"<<bucketMin<<endl;
    cout << "Bucket Max value:"<<bucketMax<<endl;
    vector<Bucket> list; // create empty Bucket vector
    Bucket *bptr;
    for(int i=0; i<bucketCount; i++) // creating bucketCount Buckets
    {
        bptr = new Bucket; // allocating new Bucket

        bptr->generate(bucketSize, bucketMin, bucketMax);

        //Bucket::generate(int,int,int,int)
        list.push_back(*bptr); // pushing Bucket onto list
        }
        for (auto it = list.begin(); it != list.end(); it++)
        {
        it->sort(); // Bucket::sort
        }
        Bucket endGame; // create empty Bucket to merge ALL buckets
        while (list.size() > 0) // vector<Bucket>::size()
        {
        endGame.merge(list[0]); // merge first bucket in list into endGame
        list.erase(list.begin()); // erase the first bucket in the list
        }
        // write all the numbers in endGame bucket to a file
        fstream out("bucketList.out", ios::out);
        for(int i=0; i<endGame.size(); i++){ // Bucket::size()

        out << endGame.atIndex(i) << endl;

        } // Bucket::atIndex(int)
        cout << "Global Swap Count:"<<globalSwapCount<<endl;
        cout << "\nbucketList.out has "<<bucketCount * bucketSize<< " sorted numbers\n";
        return 0;
    }