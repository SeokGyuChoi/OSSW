using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class csCanon : MonoBehaviour {
	public float power = 700.0f;
	Vector3 velocity = new Vector3 (0.0f, 0.5f, 0.5f);


	// Use this for initialization
	void Start () {

	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetMouseButtonDown (0)) {
			velocity = velocity * power;
			GetComponent<Rigidbody> ().AddForce (velocity);
		}
		/*if (transform.position.z > 6.0f) {
			Destroy (gameObject);
		}*/
	}

	void OnCollisionEnter(Collision coll){
		if (coll.gameObject.name == "Wall") {
			Destroy (this.gameObject, 2.0f );
			Destroy (GameObject.Find ("Wall"), 1.0f);
		}
	}



}
