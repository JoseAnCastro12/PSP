package hilos;

import java.util.Scanner;

public class HiloSumasRestas implements Runnable {
	 private int numero=1000;

	 //Constructor de la clase
	 public HiloSumasRestas (int numveces, String operacion)
	 {
		 if(operacion=="+")
		 {
			 incrementar(numveces);
			 
		 }
		 if(operacion=="-")
		 {
			 decrementar(numveces);
		 }
	 }
	 //Incrementará numero el numvece indicado
	 public int incrementar (int numveces)
	 {
		 for (int i = 0; i < numveces; i++) {
	            numero++;
	        }
	        return numero;
	 }
	 //Decrementará numero el numvece indicado
	 public int decrementar (int numveces)
	 {
		 for (int i = 0; i < numveces; i++) {
	            numero--;
	        }
	        return numero;
	 }
	 public void run() {
	 //Si la operación es “+” se invocará al método incrementar
	 //Si la operación es “-” se invocará al método decrementar
		 
		 System.out.println("Hilo: " +  Thread.currentThread().getId()+ " generando resultado final "+numero);
	}
}

