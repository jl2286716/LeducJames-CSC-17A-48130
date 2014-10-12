#ifndef ZOMBIEFUNC_H
#define ZOMBIEFUNC_H

//	Reads from and displays the 'intro.txt' file
void showFile(string name,int lines){
	ifstream inFile;
	int linePer=lines,	//	Number of lines printed per screen.
		lineCnt=0;		//	Line counter initialized to zero.
	string line,		//	Stores the lines to be written to the console.
		fName=name;		//	Stores the name of the file to be opened.
	
	//	Open the 'intro.txt' file.
	inFile.open(name,ios::in);
	if(inFile.fail()){
		cout << "The introduction is broken!\n";
	}

	//	Count the number of lines.
	while(!inFile.eof()){
		getline(inFile,line,'\n');
		lineCnt++;
	}

	//	Go back to the beninning.
	inFile.clear();
	inFile.seekg(0L,ios::beg);

	//	Iterate through and display.
	while(!inFile.eof()){
		if(lineCnt<linePer){
			for(int j=0;j<lineCnt;j++){
				getline(inFile,line,'\n');
				cout << line << endl;
			}
			system("pause");
		}else if(lineCnt>=linePer){
			for(int i=0;i<linePer;i++){
				getline(inFile,line,'\n');
				cout << line << endl;
				lineCnt--;
			}
			system("pause");
		}
	}
	inFile.close();
}



#endif