#include <iostream>

class c_point
{
	private:
		int x, y;
		
	public:
		c_point(int pos_x, int pos_y){};
		c_point(){};
};

class c_geometry
{
	private:
		c_point* point_array[100];
	public:
		c_geometry(c_point **point_list){};
		c_geometry(){};
		void add_point(const c_point &point);
		void print_distance();
		void print_num_meets();
};

int main()
{
	c_point a;
}
