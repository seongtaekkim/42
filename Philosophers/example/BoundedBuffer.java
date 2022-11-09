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
        } catch (InterruptedException e) {
            System.out.println("##### give thread : Interrupt");
        }
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
        } catch (InterruptedException e) {
            System.out.println("##### take thread : Interrupt");
        }
    }
}

class CashBox {
    private int[] buffer;
    private int count, in, out;

    public CashBox(int bufferSize) {
        buffer = new int[bufferSize];
        count = in = out = 0;
    }

    synchronized public void give(int money) throws InterruptedException {
        // critical section
        while (count == buffer.length) {
            try {
                wait();
            } catch(InterruptedException e) {
                System.out.println("##### give : Interrupt");
            }
        }
        buffer[in] = money;
        in = (in + 1) % buffer.length;
        count++;
        System.out.printf("여기있다, 용돈: %d원\n", money);
        notify();
    }

    synchronized public int take() throws InterruptedException {
        // critical section
        while (count == 0) {
            try {
                wait();
            } catch(InterruptedException e) {
                System.out.println("##### take : Interrupt");
            }
        }
        int money = buffer[out];
        out = (out + 1) % buffer.length;
        count--;
        System.out.printf("고마워, 용돈: %d원\n", money);

        notify();
        return (money);
    }
}

public class BoundedBuffer {
    public static void main(String[] args) { 
        CashBox cashBox = new CashBox(1);
        Thread[] producers = new Thread[1];
        Thread[] consumers = new Thread[1];
        // Create threads of producers
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