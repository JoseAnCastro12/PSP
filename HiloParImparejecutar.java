package hilos;

public class HiloParImparejecutar {
	
	public static void main(String[] args) {
        HiloParImpar h1 = new HiloParImpar(1);
        HiloParImpar h2 = new HiloParImpar(2);

        Thread thread1 = new Thread(h1);
        Thread thread2 = new Thread(h2);

        thread1.start();
        thread2.start();
    }
}
