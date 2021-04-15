#include <iostream.h>
#include <fstream.h>
#include <vector.h>
#include <string.h>
#include <sstream>

using namespace std;

template<class T>
class Stack{

  public:
	vector <T> icerik;
	Stack();
	void push(T obj);
	T pop();
	void yigit_dolu();
	void yigit_bos();
};


template<class T>
	Stack<T>::Stack(){

}

template<class T>
	void Stack<T>::push(T obj)
	{
		icerik.push_back(obj);
	}

template<class T>
	T Stack<T>::pop()
	{
		T back;
		if(icerik.size()==0)
		{
			return NULL;
		}
		back = icerik.back();
		icerik.pop_back();
		return back;
	}

class Process{

	public:
		vector<int> number;
		char *x[34];
		Process(){
		}
		Process(char *i[34]){*x=*i;}
		Process operator+(Process other);
		Process operator-(Process other);
		Process operator*(Process other);
		Process operator/(Process other);
		Process operator^(Process other);
		void LoadData(Stack<char> karakter , Stack<Process>sayi);

};

	int max(vector<int>a , vector<int> b)
	{
		int control=-1;
		for(int i=0;i<a.size();i++)
		{
			if(a.at(i)>b.at(i))
			{
				control=0;
				break;
			}
			else if(b.at(i)>a.at(i))
			{
				control=1;
				break;
			}
		}
		return control;
	}

	Process Process::operator+( Process other)
	{
		Process temp;     //donecek nesne
		vector <int> vec1;
		vector <int> vec2;
		vector<int> vec3;
		vector<int> vec;
		char hold[34];
		strcpy(hold,*x);
		char hold2[34];
		strcpy(hold2,*other.x);

		for(int i=0;i<strlen(hold);i++)//vektorlere aktarýlýyor
		{
			if(hold[i]!=NULL)
				vec1.push_back(hold[i]-48);
		}
		for(int i=0;i<strlen(hold2);i++)
		{
			if(hold2[i]!=NULL)
				vec2.push_back(hold2[i]-48);
		}


		if((vec1.at(0)!=-3&&vec2.at(0)!=-3) || (vec1.at(0)==-3&&vec2.at(0)==-3) )
		{//isaretlere bak
			/*if(vec1.at(0)==-3&&vec2.at(0)==-3)//sonuc kesinlikle negatif cýkacak!!!!
				cout<<"-";*/
			if(vec1.at(0)==-3 && vec2.at(0)==-3)
			{
				vec1.erase(vec1.begin());
				vec2.erase(vec2.begin());
			}
			if(vec1.size()>vec2.size())
			{
				int fazla=vec1.size()-vec2.size();
				for(int i=0;i<fazla;i++)
					vec2.insert(vec2.begin(),0);
			}
			else if(vec2.size()>vec1.size())
			{
				int fazla=vec2.size()-vec1.size();
				for(int i=0;i<fazla;i++)
					vec1.insert(vec1.begin(),0);
			}

			int elde=0;
			int vec2_size=vec2.size();
			for(int i=0 ; i < vec2_size ; i++)
			{
				int tut2=vec2.back();
				int tut1=vec1.back();
				int tasma;
				int tut3=tut1+tut2+elde;

				if(tut3>=10)
				{
					tasma=(tut3)%10;
					elde=tut3/10;
					vec3.push_back(tasma);
				}
				else
				{
					vec3.push_back(tut3);
					elde = 0;
				}
				vec1.pop_back();
				vec2.pop_back();
			}//for1
			if(elde!=0)
				vec3.push_back(elde);
		}

		else if(vec1.at(0)!=-3 && vec2.at(0)==-3)
		{
			char f='0';
			*other.x[0]=f;
			vec2.erase(vec2.begin());
			(Process)temp =  (Process)x - (Process)other.x;
		}
		else if(vec1.at(0)==-3 && vec2.at(0)!=-3)
		{
			char f='0';
			*x[0]=f;
			vec1.erase(vec1.begin());
			(Process)temp =  (Process)other.x - (Process)x;
		}

		int vec3_size=vec3.size();
		for(int i=0;i<vec3_size;i++)//vec3 ters donderýlýyor
		{
			vec.push_back(vec3.back());
			vec3.pop_back();
		}
		for(int i=0;i<vec3_size;i++)
		{
			vec3.push_back(vec.at(0));
			vec.erase(vec.begin());
		}
		for(int i=0;i<vec3_size;i++)//baþýndaki 0lar siliniyor
		{
			if(vec3.at(i)==0)
				vec3.erase(vec3.begin());
			else
				break;
		}

		temp.number.swap(vec3);
		strcpy(*x,"");
		for(int i=0;i<temp.number.size();i++)
		{
			itoa(temp.number.at(i),hold,34);
			strcat(*x,hold);
		}
		strcpy(*temp.x,*x);//vector to string

		return temp;
	}

	Process Process::operator-( Process other)
	{
		Process temp;
		vector <int> vec1;
		vector <int> vec2;
		vector<int> vec3;//cikarma
		char hold[34];
		strcpy(hold,*x);
		char hold2[34];
		strcpy(hold2,*other.x);

		for(int i=0;i<strlen(hold);i++)//vectorlere aktar
		{
			if(hold[i]!=NULL)
				vec1.push_back(hold[i]-48);
		}
		for(int i=0;i<strlen(hold2);i++)
		{
			if(hold2[i]!=NULL)
				vec2.push_back(hold2[i]-48);
		}

		int elde=0;

		if(vec1.at(0)==-3 && vec2.at(0)==-3)
		{

			vec1.erase(vec1.begin());
			vec2.erase(vec2.begin());
			int vec2_size=vec2.size();
			int vec1_size=vec1.size();

			if(vec1.size()>vec2.size())
			{
				int fazla=vec1.size()-vec2.size();
				for(int i=0;i<fazla;i++)
					vec2.insert(vec2.begin(),0);

				for(int i=0;i<vec1_size;i++)
				{
					int tut2=vec2.back();
					int tut1=vec1.back();
					if(tut1>=tut2)
					{
						vec3.push_back(tut1-tut2);
						vec1.pop_back();
						vec2.pop_back();
					}
					else
					{
						vec3.push_back((tut1+10)-tut2);
						vec1.pop_back();
						int artan=vec1.back()-1;
						vec1.pop_back();
						vec1.push_back(artan);
						vec2.pop_back();
					}
				}
			}
			else if(vec2.size()>vec1.size())
			{
				int fazla=vec2.size()-vec1.size();
				for(int i=0;i<fazla;i++)
					vec1.insert(vec1.begin(),0);

				for(int i=0;i<vec2_size;i++)
				{
					int tut2=vec2.back();
					int tut1=vec1.back();
					if(tut2>=tut1)
					{
						vec3.push_back(tut2-tut1);
						vec1.pop_back();
						vec2.pop_back();
					}
					else
					{
						vec3.push_back((tut2+10)-tut1);
						vec2.pop_back();
						int artan=vec2.back()-1;
						vec2.pop_back();
						vec2.push_back(artan);
						vec1.pop_back();
					}
				}
			}

			else // boyutlar eþit ama hangisinin büyük olduðu bilinmiyor!!!!!
			{
				int control=max(vec1,vec2);
				if(control==0)
				{
					for(int i=0;i<vec1_size;i++)
					{
						int tut2=vec2.back();
						int tut1=vec1.back();
						if(tut1>=tut2)
						{
							vec3.push_back(tut1-tut2);
							vec1.pop_back();
							vec2.pop_back();
						}
						else
						{
							vec3.push_back((tut1+10)-tut2);
							vec1.pop_back();
							int artan=vec1.back()-1;
							vec1.pop_back();
							vec1.push_back(artan);
							vec2.pop_back();
						}
					}
				}
				else if(control==1)
				{
					for(int i=0;i<vec2_size;i++)
					{
						int tut2=vec2.back();
						int tut1=vec1.back();
						if(tut2>=tut1)
						{
							vec3.push_back(tut2-tut1);
							vec1.pop_back();
							vec2.pop_back();
						}
						else
						{
							vec3.push_back((tut2+10)-tut1);
							vec2.pop_back();
							int artan=vec2.back()-1;
							vec2.pop_back();
							vec2.push_back(artan);
							vec1.pop_back();
						}
					}
				}
				else
					cout<<"0";	//sonuc sýfýr olacak
			}
		}

		else if(vec1.at(0)==-3 && vec2.at(0)!=-3)
		{
			char f='0';
			*x[0]=f;
			(Process)temp =  (Process)x + (Process)other.x;
		}

		else if(vec1.at(0)!=-3 && vec2.at(0)==-3)
		{
			char f='0';
			*other.x[0]=f;
			(Process)temp =  (Process)x + (Process)other.x;
		}
		else
		{
			int vec2_size=vec2.size();
			int vec1_size=vec1.size();

			if(vec1.size()>vec2.size())
			{
				int fazla=vec1.size()-vec2.size();
				for(int i=0;i<fazla;i++)
					vec2.insert(vec2.begin(),0);

				for(int i=0;i<vec1_size;i++)
				{
					int tut2=vec2.back();
					int tut1=vec1.back();
					if(tut1>=tut2)
					{
						vec3.push_back(tut1-tut2);
						vec1.pop_back();
						vec2.pop_back();
					}
					else
					{
						vec3.push_back((tut1+10)-tut2);
						vec1.pop_back();
						int artan=vec1.back()-1;
						vec1.pop_back();
						vec1.push_back(artan);
						vec2.pop_back();
					}
				}
			}
			else if(vec2.size()>vec1.size())
			{
				int fazla=vec2.size()-vec1.size();
				for(int i=0;i<fazla;i++)
					vec1.insert(vec1.begin(),0);

				for(int i=0;i<vec2_size;i++)
				{
					int tut2=vec2.back();
					int tut1=vec1.back();
					if(tut2>=tut1)
					{
						vec3.push_back(tut2-tut1);
						vec1.pop_back();
						vec2.pop_back();
					}
					else
					{
						vec3.push_back((tut2+10)-tut1);
						vec2.pop_back();
						int artan=vec2.back()-1;
						vec2.pop_back();
						vec2.push_back(artan);
						vec1.pop_back();
					}
				}
			}

			else // boyutlar eþit ama hangisinin büyük olduðu bilinmiyor!!!!!
			{
				int control=max(vec1,vec2);
				if(control==0)
				{
					for(int i=0;i<vec1_size;i++)
					{
						int tut2=vec2.back();
						int tut1=vec1.back();
						if(tut1>=tut2)
						{
							vec3.push_back(tut1-tut2);
							vec1.pop_back();
							vec2.pop_back();
						}
						else
						{
							vec3.push_back((tut1+10)-tut2);
							vec1.pop_back();
							int artan=vec1.back()-1;
							vec1.pop_back();
							vec1.push_back(artan);
							vec2.pop_back();
						}
					}
				}
				else if(control==1)
				{
					for(int i=0;i<vec2_size;i++)
					{
						int tut2=vec2.back();
						int tut1=vec1.back();
						if(tut2>=tut1)
						{
							vec3.push_back(tut2-tut1);
							vec1.pop_back();
							vec2.pop_back();
						}
						else
						{
							vec3.push_back((tut2+10)-tut1);
							vec2.pop_back();
							int artan=vec2.back()-1;
							vec2.pop_back();
							vec2.push_back(artan);
							vec1.pop_back();
						}
					}
				}
				else
					cout<<"0";//Sonuc sýfýr olacak
			}
		}

		temp.number.swap(vec3) ;
		int temp_number_size=temp.number.size();
		vector<int> vec;
		for(int i=0;i<temp_number_size;i++)//temp.number ters donderýlýyor
		{
			vec.push_back(temp.number.back());
			temp.number.pop_back();
		}
		for(int i=0;i<temp_number_size;i++)
		{
			temp.number.push_back(vec.at(0));
			vec.erase(vec.begin());
		}
		strcpy(*x,"");
		strcpy(*temp.x,*x);
		for(int i=0;i<temp.number.size();i++)
		{
			itoa(temp.number.at(i),hold,34);
			strcat(*temp.x,hold);
		}
	    return temp;
	}

	Process Process::operator*( Process other)
	{
		Process temp;
		vector <int> vec1;
		vector <int> vec2;
		vector <int> vec3;
		vector <int> vec4;
		vector <int> vec5;
		char hold[34];
		strcpy(hold,*x);
		char hold2[34];
		strcpy(hold2,*other.x);
		for(int i=0;i<strlen(hold);i++)
		{
			if(hold[i]!=NULL)
				vec1.push_back(hold[i]-48);
		}
		for(int i=0;i<strlen(hold2);i++)
		{
			if(hold2[i]!=NULL)
				vec2.push_back(hold2[i]-48);
		}
		vector<int> vec;
		int vec2_size=vec2.size();
		int vec1_size=vec1.size();
		for(int i=0;i<vec2_size;i++)//vec2 ters donderýlýyor
		{
			vec.push_back(vec2.back());
			vec2.pop_back();
		}
		for(int i=0;i<vec2_size;i++)
		{
			vec2.push_back(vec.at(0));
			vec.erase(vec.begin());
		}
		vec.clear();
		for(int i=0;i<vec1_size;i++)//vec1 ters donderýlýyor
		{
			vec.push_back(vec1.back());
			vec1.pop_back();
		}
		for(int i=0;i<vec1_size;i++)
		{
			vec1.push_back(vec.at(0));
			vec.erase(vec.begin());
		}

		int basamak=vec2.size();
		int basamak2=vec1.size();
		int elde=0;
		for(int i=0 ; i < vec2.size() ; i++)
		{
			int tut2=vec2.at(i);
			for(int j=0 ; j < vec1.size() ; j++)
			{
				int tut1=vec1.at(j);
				int tasma;
				int tut3=tut1*tut2+elde;

				if(tut3>=10)
				{
					tasma=(tut3)%10;
					elde=tut3/10;
					vec3.push_back(tasma);
				}
				else
				{
					vec3.push_back(tut3);
					elde = 0;
				}
			}//for1

			int vec3_size_tut = vec3.size();
			if(elde==0)
			{
				for(int h=vec3_size_tut;h<basamak+basamak2;h++)
				vec3.push_back(0);
			}
			else
			{
				vec3.push_back(elde);
				for(int h=vec3_size_tut;h<basamak+basamak2-1;h++)
					vec3.push_back(0);
			}
			elde=0;
			basamak--;
			for(int f=0;f<i;f++)
				vec3.insert(vec3.begin(),0);

			if(vec4.size() == 0)//vec3 vec4 e aktarýlýyor
			{
				while(vec3.size()!=0)
				{
					vec4.push_back(vec3.back());
					vec3.pop_back();
				}
			}
			else
			{
				int vec3_size=vec3.size();
				for(int h=0;h<vec3_size;h++)
				{
					int i=0;
					int tasma;
					int k=vec4.back();
					int m=vec3.at(i);
					if(k+m+elde>=10)
					{
						tasma = (k+elde+m)%10;
						elde=(k+elde+m)/10;
						vec5.push_back(tasma);
					}
					else
					{
						tasma=(k+m+elde);
						vec5.push_back(tasma);
						elde=0;
					}
					vec4.pop_back();
					vec3.erase(vec3.begin());
				}
				if(elde!=0)
					vec5.push_back(elde);
				int vec5_size=vec5.size();
				for(int i=0;i<vec5_size;i++)
					vec4.push_back(vec5.at(i));
				int vec4_size=vec4.size();
				vector<int> vec;
				for(int i=0;i<vec4_size;i++)//vec4 ters donderýlýyor
				{
					vec.push_back(vec4.back());
					vec4.pop_back();
				}
				for(int i=0;i<vec4_size;i++)
				{
					vec4.push_back(vec.at(0));
					vec.erase(vec.begin());
				}
				vec5.clear();
			}
		}//for2
		temp.number.swap(vec4) ;
		for(int i=0;i<temp.number.size();i++)//baþýndaki 0lar siliniyor
		{
			if(temp.number.at(i)==0)
			{
				temp.number.erase(temp.number.begin());
				i--;
			}
			else
				break;
		}
		strcpy(*x,"");
		strcpy(*temp.x,*x);
		for(int i=0;i<temp.number.size();i++)
		{
			itoa(temp.number.at(i),hold,34);
			strcat(*temp.x,hold);
		}
		return temp;
	}

	Process Process::operator/( Process other)
	{
		Process temp;
		int sayac = 0;
		vector <int> vec1;
		vector <int> vec2;
		vector<int> vec3;
		vector<int> vec;

		char hold[34];
		char hold2[34];
		strcpy(hold,*x);
		strcpy(hold2,*other.x);

		for(int i=0;i<strlen(hold);i++)
		{
			if(hold[i]!=NULL)
				vec1.push_back(hold[i]-48);
		}
		for(int i=0;i<strlen(hold2);i++)
		{
			if(hold2[i]!=NULL)
				vec2.push_back(hold2[i]-48);
		}
		int vec2_tut=vec2.size();
		if(vec1.size()>vec2.size())
		{
			int fazla=vec1.size()-vec2.size();
			for(int i=0;i<fazla;i++)
				vec2.insert(vec2.begin(),0);
		}
		if(vec1.size()>vec2.size())
		{
			int fazla=vec1.size()-vec2.size();
			for(int i=0;i<fazla;i++)
				vec2.insert(vec2.begin(),0);
		}

		int control=max(vec1,vec2);

		if(control==1)
			cout<<"sonuc:0";//sonuc kesinlikle 0 olacak
		else if(control==-1)
			cout<<"sonuc:1";//sonuc kesinlikle 1;

		while(control==0)
		{
			temp = (Process)x - (Process)other.x;
			vec1.swap(temp.number);
			temp.number.clear();
			char hold[34];
			strcpy(*x,"");
			for(int i=0;i<vec1.size();i++)
			{
				itoa(vec1.at(i),hold,34);
				strcat(*x,hold);
			}
			control=max(vec1,vec2);
			sayac++;
		}
		sayac++;
		cout<<"\n"<<sayac;//sonuç!!!// sayacý temp degýskenýn býr nýtelýgýne ata!!!daha yapýlmadý
		return temp;
	}
	//}
	Process Process::operator^( Process other)
	{
		Process temp;
		vector <int> vec1;
		vector <int> vec2;
		vector<int> vec3;
		vector<int> vec;
		char hold[34];
		strcpy(hold,*x);
		char hold2[34];
		strcpy(hold2,*other.x);

		int k=atoi(*other.x);
		for(int i=0;i<k;i++)
		{
			strcpy(*other.x,hold);
			temp = (Process)x  * (Process)other.x;
			strcpy(*x,*temp.x);
		}
		strcpy(*temp.x,*x);
		return temp;
	}

	void Process::LoadData(Stack<char> karakter , Stack<Process>sayi)
	{
		Process * h=new Process();
		char taken[255];
		string str;
		ifstream infile("data.txt");
		ofstream outfile("output.txt");
		char * pch;
		while (!infile.eof()) {
			infile.getline(taken,254);
			pch = strtok (taken," ");
			while (pch != NULL)
			{
				if(*pch == '+' || *pch == '-' || *pch == '*' || *pch == '/' || *pch == '^' )
				{
					int control = atoi(pch);
					if(control != 0)
						sayi.push(&pch);

					else
						karakter.push(*pch);
				}

				else
				{
					sayi.push(&pch);
				}
				pch = strtok (NULL, " ");
			}

			while(karakter.icerik.size() != 0)
			{
				char character = karakter.pop();
				if(character == '*')
				{
					*h  = (Process)sayi.pop() * (Process)sayi.pop();
					sayi.push(*h);
				}
				else if(character == '^')
				{
					* h = (Process)sayi.pop() ^ (Process)sayi.pop();
					sayi.push(*h);
				}
				else if(character == '+')
				{
					* h = (Process)sayi.pop() + (Process)sayi.pop();
					sayi.push(*h);
				}
				else if(character == '-')
				{
					* h  = (Process)sayi.pop() - (Process)sayi.pop();
					sayi.push(*h);

				}
				else if(character == '/')
				{
					Process temp = (Process)sayi.pop();
					Process temp1 = (Process)sayi.pop();
					if(temp1.x == 0 )
					{
						cout<<"NaN";
						break;
					}
					else
					{
						temp = (Process)temp1 / (Process)temp;
						sayi.push(temp);
					}
				}
			}
		}
		outfile<<*sayi.pop().x;
	}

	int main()
	{
		Stack<char> karakter;
		Stack<Process> sayi;
		Process k;
		k.LoadData(karakter , sayi);

	}
