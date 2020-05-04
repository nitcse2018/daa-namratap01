import java.io.IOException;

class Q{
	int num;
	boolean val=false;
	public synchronized void put(int num) {
		while(val) {
			try {
				wait();
			} catch (InterruptedException e) {}
		}
			this.num=num;
			System.out.println("Put" + num);
			val=true;
			notify();
	}
	
	public synchronized void get()
	{
		while(!val) {
			try {
				wait();
			} catch (InterruptedException e) {}
		}
		System.out.println("Get" + num);
		val=false;
		notify();
	}
}

class Producer implements Runnable{
	Q ob;
	
	Producer(Q ob){
		this.ob=ob;
		Thread t1=new Thread(this);
		t1.start();
	}
	
	public void run() {
		int i=0;
		while(true) {
			ob.put(i++);
			try {Thread.sleep(1000);} catch(Exception e) {}
		}
	}
}

class Consumer implements Runnable{
	Q ob;
	
	Consumer(Q ob){
		this.ob=ob;
		Thread t2=new Thread(this);
		t2.start();
	}
	
	public void run() {
		while(true) {
			ob.get();
			try {Thread.sleep(2000);} catch(Exception e) {}
		}
	}
}

public class ProducerConsumer {

	public static void main(String[] args) throws IOException, InterruptedException{
		Q o1=new Q();
		new Producer(o1);
		new Consumer(o1);
	
	}
}

