import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class File_Handling_bytestream {
public static void main(String[] args) throws IOException{
		
		FileInputStream fr=null;
		FileOutputStream fw=null;
		try {
			fr=new FileInputStream("input.txt");
			fw=new FileOutputStream("output_byte.txt");
			
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
