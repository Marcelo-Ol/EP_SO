package EP1;
class ProcessosFilho extends Thread{
    private int numThread;

    public ProcessosFilho(int numThread){
        this.numThread = numThread;
    }

    @Override
    public void run(){
        System.out.println("Hello World, Processo Filho " + numThread);
    }
}