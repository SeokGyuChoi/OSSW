using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class csBoom : MonoBehaviour {
	//public GameObject Ball;
	//public Transform Firepoint;

	void OnCollisionEnter(Collision coll)
	{
		if(coll.gameObject.tag == "Hiyoko")
		{
			Destroy (gameObject);
			Destroy (coll.gameObject);
		}
	}
}