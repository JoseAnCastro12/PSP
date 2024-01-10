package hilos;

public class HiloParImparrunnable implements Runnable {
    // Atributos
    private int numHilo;

    // Constructor
    public HiloParImparrunnable(int numHilo) {
        this.numHilo = numHilo;
    }

    @Override
    public void run() {
        
        switch (numHilo) {
            case 1:
                
                for (int i = 101; i <= 200; i++) {
                    if (i % 2 == 1)
                        System.out.println("HILO " + Thread.currentThread().getId() + " generando número impar " + i);
                }
                break;
                
            case 2:
            	for (int i = 1; i <= 100; i++) {
                    if (i % 2 == 0)
                        System.out.println("HILO " + Thread.currentThread().getId() + " generando número par " + i);
                }
            	break;
        }
    }

    
}
