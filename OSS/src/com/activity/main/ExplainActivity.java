package com.activity.main;

import android.app.Activity;
import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnTouchListener;
import android.widget.Button;
import android.widget.ImageView;

import com.greathw.main.R;

public class ExplainActivity extends Activity {

	ImageView btnnext;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		setContentView(R.layout.explain);
		
		btnnext = (ImageView)findViewById(R.id.explainnextbutton);
		btnnext.setOnClickListener(new Button.OnClickListener(){
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				startActivity(new Intent( ExplainActivity.this, MenuActivity.class));
				finish();
			}
		});
		btnnext.setOnTouchListener(new OnTouchListener() { //��ư ��ġ�� �̺�Ʈ        
            public boolean onTouch(View v, MotionEvent event) {
                if(event.getAction() == MotionEvent.ACTION_DOWN) // ��ư�� ������ ���� ��
                    btnnext.setBackgroundColor(Color.LTGRAY);
                if(event.getAction() == MotionEvent.ACTION_UP){ //��ư���� ���� ������ �� 
                    btnnext.setBackgroundColor(Color.TRANSPARENT); 
                }
                return false;
            }
        }); 
	}
	
}
