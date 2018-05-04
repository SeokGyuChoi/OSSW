using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class csMove : MonoBehaviour {

	float speed = 10.0f;
	//float rot = 100.0f;

	// Use this for initialization
	void Start () {
		transform.position = new Vector3 (0.0f, 3.0f, -2.0f);

		//transform.Translate (new Vector3 (3.0f, 0.5f, 0.0f));
	}
	
	// Update is called once per frame
	void Update () {
		float h = Input.GetAxis ("Horizontal");
		float v = Input.GetAxis ("Vertical");

		h = h * Time.deltaTime * speed;
		v = v * Time.deltaTime * speed;

		transform.Translate (Vector3.right * h);
		transform.Translate (Vector3.forward * v);
		//transform.Rotate (Vector3.up * h);
		//transform.Rotate (Vector3.right * v);


		}


}
