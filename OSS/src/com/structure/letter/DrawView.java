package com.structure.letter;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Toast;

public class DrawView extends View {
	
	Paint mPaint; Stroke freeStr = new Stroke();

	Toast mToast;
	
	public DrawView(Context context) {
		super(context);
		// TODO Auto-generated constructor stub			
		mPaint = new Paint(); mPaint.setColor(Color.BLACK); mPaint.setStrokeWidth(3);
		mPaint.setAntiAlias(true); freeStr.init();
	}
	
	@Override
    public boolean onTouchEvent(MotionEvent event) {
		switch (event.getAction()) {
        case MotionEvent.ACTION_DOWN:
        	freeStr.AddPoint( event.getX(), event.getY(),false ); break;
        case MotionEvent.ACTION_MOVE:
           	freeStr.AddPoint( event.getX(), event.getY(),true ); break;
		}
        invalidate();
        return true;
	}

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
            freeStr.DrawStroke(canvas, mPaint);
    }
    
    public void erase()
    {
    	freeStr.init();
    	invalidate();
    }

}
