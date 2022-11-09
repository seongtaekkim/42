class SharedDB {
    private int readerCount = 0;
    private boolean isWriteing = false;

    public void read() {

    }

    public void write() {

    }

    synchronized public void acquireReadLock() {
        while (isWriting == true) {
            try {
                wait();
            } catch (InterruptedException e) {}
        }
        readerCount++;
    }

    synchronized public void releaseReadLock() {
        readerCount--;
        if (readerCount == 0)
            notify();
    }

    synchronized public void acquireWriteLock() {
        while (readerCount > 0 || isWriteing == false) {
            try {
                wait();
            } catch (InterruptedException e) {}
        }
        isWriting = true;
    }
    
    synchronized public void releaseWriteLock() {
        isWriting = true;
        notifyAll();
    }
}

