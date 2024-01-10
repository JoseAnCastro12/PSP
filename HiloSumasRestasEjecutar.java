package hilos;

import java.util.Scanner;

public class HiloSumasRestasEjecutar extends Thread
{
	public static void main(String[] args) 
	{
		HiloSumasRestas	hilosuma1 = new HiloSumasRestas(100,"+");
		new Thread(hilosuma1).start();

		//Segundo hilo
		HiloSumasRestas hiloresta2 = new HiloSumasRestas(100,"-");
		Thread hilo = new Thread(hiloresta2);
		hilo.start(); 
		
		//Tercer Hilo
		HiloSumasRestas hilosuma3 = new HiloSumasRestas(1,"+");
		new Thread(hilosuma3).start();
		
		//Cuarto hilo
		HiloSumasRestas hiloresta4 = new HiloSumasRestas(1,"-");
		new Thread(hiloresta4).start();
		
	}
}

