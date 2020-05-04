import java.util.concurrent.locks.*;
import java.util.Queue;
import java.util.LinkedList;

class BlockingQueue<Q>{
	private int capacity;
	private Queue<Q> queue;
	
	private ReentrantLock lock=new ReentrantLock(true); 
	private Condition notFull= lock.newCondition();
	private Condition notEmpty= lock.newCondition();
	
	public
		BlockingQueue(int capacity){
		queue=new LinkedList<>();
		this.capacity=capacity;
		}
		
		void put(Q e) throws InterruptedException{
			lock.lock();
			try {
				while(queue.size()==capacity) {
					System.out.println(Thread.currentThread().getName() + " : Buffer is full, waiting");
					notFull.await();
				}
				queue.add(e);
				System.out.println("Pushed " + e + " to Queue");
				notEmpty.signalAll();
			} finally {
				lock.unlock();
			}
			
		}
		
		Q take() throws InterruptedException {
			lock.lock();
			try {
				while(queue.size()==0) {
					System.out.println(Thread.currentThread().getName() + " : Buffer is empty, waiting");
					notEmpty.await();
				}
				Q item=queue.remove();
				System.out.println("Removed " + item + " from Queue");
				
				notFull.signalAll();
				return item;
			} finally {
				lock.unlock();
			}	
		}
}


class Producer implements Runnable{
	BlockingQueue ob;
	
	Producer(BlockingQueue ob){
		this.ob=ob;
		Thread t1=new Thread(this,"Producer");
		t1.start();
	}
	
	public void run() {
		int i=0;
		while(true) {
			try {
				ob.put(i++);
			} catch (Exception e1) {
				e1.printStackTrace();
			}
			try {Thread.sleep(1000);} catch(Exception e) {}
		}
	}
}

class Consumer implements Runnable{
	BlockingQueue ob;
	
	Consumer(BlockingQueue ob){
		this.ob=ob;
		Thread t2=new Thread(this,"Consumer");
		t2.start();
	}
	
	public void run() {
		while(true) {
			try {
				ob.take();
			} catch (InterruptedException e1) {
				e1.printStackTrace();
			}
			try {Thread.sleep(2000);} catch(Exception e) {}
		}
	}
}


public class ProducerConsumer_locks {

	public static void main(String[] args) {
		BlockingQueue o1=new BlockingQueue(10);
		new Producer(o1);
		new Consumer(o1);

	}

}
