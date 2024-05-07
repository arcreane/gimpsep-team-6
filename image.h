#pragma once
using namespace std;

class Image {
	private:
		Mat image;
		Size dimensions;
	public: 
		Image(const string& path);
		void save(const string& path);
		void display();
		Size getDimensions() const;


};