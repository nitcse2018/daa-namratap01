package first;

import java.io.IOException;
import java.io.FileWriter;
import java.io.FileReader;

public class File_Handling_charstream {

	public static void main(String[] args) throws IOException{
		
		FileReader fr=null;
		try {
			fr=new FileReader("input.txt");
			FileWriter fw=new FileWriter("output.txt");
			
			int ch;
			while((ch=fr.read())!=-1) {
				fw.write(ch);
			}
			
			fw.close();
			fr.close();
		}
		catch(Exception e){
			System.out.println("Action could not be performed");
		}
		
		
		
	}

}
