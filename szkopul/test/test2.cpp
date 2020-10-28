#include<iostream>
#define pkt punkt
using namespace std;

struct punkt{
    int x;
    int y;
};

int iloczyn(pkt a, pkt b, pkt c){
	return (c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y);
}

bool sprawdz(pkt X, pkt Y, pkt Z)
{
	return min(X.x, Y.x) <= Z.x && Z.x <= max(X.x, Y.x) 
		&& min(X.y, Y.y) <= Z.y && Z.y <= max(X.y, Y.y);
}

bool przecina(pkt A, pkt B, pkt C, pkt D)
{
	int il1 = iloczyn(C, D, A);
    int	il2 = iloczyn(C, D, B);
	int	il3 = iloczyn(A, B, C);
	int	il4 = iloczyn(A, B, D);

        cout << il1 << " " << il2 << " " << il3 << " " << il4 << endl;
        cout << A.x << " " << A.y << " " << B.x << " " << B.y << C.x << " " << C.y << D.x << " " << D.y << endl;

	if((il1>0&&il2<0||il1<0&&il2>0)&&(il3>0&&il4<0||il3<0&&il4>0)) return 1;
	
	if(il1 == 0 && sprawdz(C, D, A)) return 1;
	if(il2 == 0 && sprawdz(C, D, B)) return 1;
	if(il3 == 0 && sprawdz(A, B, C)) return 1;
	if(il4 == 0 && sprawdz(A, B, D)) return 1;
	
	return 0;
}
int main()
{
	punkt A, B, C, D;
	
	//definiujemy dwa odcinki skierowane A->B oraz C->D
	cout<<"Podaj wspólrzedne punktu A: ";
	cin>>A.x>>A.y;
	
	cout<<"Podaj wspólrzedne punktu B: ";
	cin>>B.x>>B.y;
	
	cout<<"Podaj wspólrzedne punktu C: ";
	cin>>C.x>>C.y;
	
	cout<<"Podaj wspólrzedne punktu D: ";
	cin>>D.x>>D.y;

	if(czy_przecinaja(A, B, C, D)) 
		cout<<"Odcinki sie przecinaja\n";
	else
		cout<<"Odcinki sie nie przecinaja\n";
	
	return 0;
}