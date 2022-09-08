#include<iostream>

struct coord{
	
	int x;
	int y;
	
	
	int get_x(){
		return x;
	}
	
	void print_xy(){
		std::cout <<"("<<x<<"," <<y <<")" <<std::endl;
	}
	
	struct coord get_point(){
		coord crd = {x,y};
		return crd;
	};
	
};

int main(){
	
	coord crd = {12,24};
	
	crd.print_xy();
	crd = crd.get_point();
	return 0;
}
