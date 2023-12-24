package EP1;
public class Main extends Thread{
    public static void main(String[] args) {
        System.out.println("Hello World, Processo pai"); //Processo pai

        //Cria e armazena 10 processos filhos em um vetor de threads
        ProcessosFilho[] threads = new ProcessosFilho[10];

        for(int i = 0; i < 10; i++){
        ProcessosFilho thread = new ProcessosFilho(i);
        threads[i] = thread;
        thread.start();
        }

    try{
        for (ProcessosFilho thread : threads){
            thread.join();
        }
        } catch (InterruptedException e){
            e.printStackTrace();
        }

        System.out.println("Finalizando Processo Pai");
    }
}

