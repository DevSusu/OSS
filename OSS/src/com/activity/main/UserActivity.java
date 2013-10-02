package com.activity.main;

import java.io.IOException;
import java.io.OutputStreamWriter;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Toast;

import com.greathw.main.R;

public class UserActivity extends Activity {

	String check;
	String path;
	EditText name;
	EditText age;
	CheckBox sex;
	ImageView btnsave;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		setContentView(R.layout.user);

		name = (EditText) findViewById(R.id.usernametext);
		age = (EditText) findViewById(R.id.useragetext);
		btnsave = (ImageView) findViewById(R.id.usersavebutton);
		btnsave.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				
				OutputStreamWriter osw = null;

				try {
					
					osw = new OutputStreamWriter( openFileOutput("text.txt", Context.MODE_PRIVATE));
					osw.write( name.getText().toString() + age.getText().toString() );

					startActivity(new Intent(UserActivity.this,
							ExplainActivity.class));
					finish();

				} catch (Exception e) {
					Toast.makeText(UserActivity.this,
							"파일 저장에 실패했습니다. SD 카드가 제대로 장착되었는지 확인해주세요",
							Toast.LENGTH_LONG).show();
				} finally
				{
					try {
						osw.close();
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			}
		});
	}
}
