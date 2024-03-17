enum ErrCode { QUEUE_ALLOCATION(2), QUEUE_IS_EMPTY(1), OTHER_ERROR(0);
    int mCode;
    ErrCode( int code ) { mCode = code; }
}

class FifoException extends RuntimeException {
    private ErrCode mErrCode = ErrCode.OTHER_ERROR;
    FifoException( ErrCode errCode ){
        mErrCode = errCode;
    }

    public String getReason() {
        //System.out.println( "mErrCode " + ErrCode.OTHER_ERROR );
        switch ( mErrCode ) {
            case QUEUE_IS_EMPTY : return "Queue is empty\n";
            case QUEUE_ALLOCATION: return "Memory allocation error\n";
            default: return "Other Error\n";
        }
    }
}
public class FQueue<T> {
    private class FifoItem<T>{
        private T mItem;
        private FifoItem mNext;
        public FifoItem( T c ) {
            mItem = c;
            mNext = null;
        }
        public T getItem() {
            return mItem;
        }
        public FifoItem getNext() {
            return mNext;
        }
    }

    private FifoItem mHead = null;
    private FifoItem mTail = null;

    public final int Enqueue( T c ) throws FifoException {
        try {
            FifoItem f = new FifoItem(c);
            if( mHead == null ){
                mHead = f;
            }
            else {
                mTail.mNext = f;
            }
            mTail = f;
        }
        catch( OutOfMemoryError e ) {
            throw new FifoException( ErrCode.QUEUE_ALLOCATION );
        }
        return 0;
    }

    public final T Dequeue(){
        if( FQEmpty()){
            throw new FifoException( ErrCode.QUEUE_IS_EMPTY );
        }
        T info = (T)mHead.getItem();
        FQDel();
        return info;
    }

    private void FQDel(){
        if( FQEmpty()){
            throw new FifoException( ErrCode.QUEUE_IS_EMPTY );
        }
        mHead = mHead.getNext();
    }

    public boolean FQEmpty(){
        return mHead==null;
    }
}
