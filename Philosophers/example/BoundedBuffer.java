class ProdRunner implements Runnable {
    CashBox cashBox;
    public ProdRunner(CashBox cashBox) {
        this.cashBox = cashBox;
    }
    @Override
    public void run() {
        try {
            while (true) {
                Thread.sleep((long)(Math.random()*500));
                int money = ((int)(1 + Math.random()*9))*10000;
                cashBox.give(money);
            }
        } catch (InterruptedException e) {}
    }
}

class ConsRunner implements Runnable {
    CashBox cashBox;
    public ConsRunner(CashBox cashBox) {
        this.cashBox = cashBox;
    }
    @Override
    public void run() {
        try {
            while (true) {
                Thread.sleep((long)(Math.random()*500));
                int money = cashBox.take();
            }
        } catch (InterruptedException e) {}
    }
}

public class BoundedBuffer {
    public static void main(String[] args) { 
        CashBox cashBox = new CashBox(1); Thread[] producers = new Thread[1]; Thread[] consumers = new Thread[1]; // Create threads of producers
        for (int i = 0; i < producers.length; i++) {
            producers[i] = new Thread(new ProdRunner(cashBox));
            producers[i].start();
        }
        // Create threads of consumers
        for (int i = 0; i < consumers.length; i++) {
            consumers[i] = new Thread(new ConsRunner(cashBox));
            consumers[i].start();
        } 
    }
}