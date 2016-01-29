import java.io.*;

public class ReadFile {
	public static void main(String[] args){
		String chaine="";
		String fichier ="Nouveau.txt";
		String addr[];
		String addr1;
		int addrint;
		//lecture du fichier texte	
		try{
			InputStream ips=new FileInputStream(fichier); 
			InputStreamReader ipsr=new InputStreamReader(ips);
			BufferedReader br=new BufferedReader(ipsr);
			String ligne;
			while ((ligne=br.readLine())!=null){
				
		             addr = ligne.split(" ");
		             addr1=addr[3];
		             addrint=   Integer.parseInt(addr1, 16) ; 
				
				System.out.println(addrint);
				chaine+=ligne+"\n";
			}
			br.close(); 
		}		
		catch (Exception e){
			System.out.println(e.toString());
		}
	}
}
	
