package cs251lab10package;

import java.io.BufferedReader;//read text from character - based input stream
import java.io.EOFException;//End of File / Stream
import java.io.IOException;//thrown whenever an input or output operation is failed or interpreted
import java.io.InputStreamReader;//reads bytes and translates them into characters
import java.io.ObjectInputStream;//enables to read Java objects from an InputStream instead of just raw bytes
import java.io.ObjectOutputStream;//enables to write Java objects to an OutputStream instead of just raw bytes
import java.io.PrintWriter;//enables you to write formatted data to an underlying Writer
/* Socket represents one end of a two-way connection between your Java program and another program on the network.
Socket provides a mechanism for the server program to listen for clients and establish connections with them.*/
import java.net.ServerSocket;//implements the server side of the two-way link
import java.net.Socket;//implements the client side of the two-way link
import java.net.SocketException;


public class JChatComm {
	String type;
	String hisPublic;
	String hisModulus;
	String myPublicKey;
	String myModulus;
	RSA myrsa;
	ObjectInputStream in;
    ObjectOutputStream out;
    BufferedReader stdIn;
    Socket socket;
    int count1=0;
    int count2=0;
    public JChatComm(Socket echoSocket,ObjectInputStream in,ObjectOutputStream out, String type) {
    	myrsa = new RSA();
    	myPublicKey = myrsa.getPublicKey();
    	myModulus = myrsa.getModulus();
        this.type = type;
    	this.socket = echoSocket;
    	this.out = out;
    	this.in = in;
        stdIn = new BufferedReader(
                new InputStreamReader(System.in));
    }
    
    public void sendMessage(JPacket inputString) throws EOFException, SocketException {
    
    	if (count1==0||count1==1){
    	}
    	else
    	inputString.core.text = myrsa.encrypt(inputString.core.text,hisModulus,hisPublic);
        try {
            out.writeObject(inputString);
            count1+=1;
        } catch (IOException e) {

            e.printStackTrace();
        }
    }
    
    public JPacket receiveMessage() throws IOException, ClassNotFoundException, SocketException, EOFException {
        JPacket temp = (JPacket) in.readObject();
        
        if(count2==0||count2==1){
        	
        }
        else{
        	if (type.equalsIgnoreCase("Client")){
        		System.out.println("Server: ");
        	}
        	else {
        		System.out.println("Client: ");
        	}
        	System.out.println("Encrypted Message: "+temp.core.text);
        	temp.core.text = myrsa.decrypt(temp.core.text);
	        System.out.println("Decrypted Message: "+temp.core.text);
	 
	        
        }
        count2+=1;
        return temp;
    }
    
    public void endChat() {
        //System.out.println("Inside endChat()!");
        try {
            socket.close();
            in.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
