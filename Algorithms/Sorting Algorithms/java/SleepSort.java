import java.io.IOException;

public class SleepSort {

	public static void main(String[] args) throws IOException {
		
		int n[] = {3,1,6,25,20,10};
		
		for(int i = 0; i <n.length; i++) {
			Thr thr = new Thr(n[i]);
			Thread t = new Thread(thr);
			t.start();
		}
	}

	static class Thr implements Runnable {
		int num;

		Thr(int num) {
			this.num = num;
		}

		public void run() {
			try {
				Thread.sleep(num*1000); // sleep 'num' seconds
				System.out.println(num);	
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			
		}
	}

}
