using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class csRaycast : MonoBehaviour {


	// Update is called once per frame
	void Update ()
	{
		Debug.DrawRay (transform.position, transform.forward * 8, Color.red);
		RaycastHit hit;

		if (Physics.Raycast (transform.position, transform.forward, out hit, 8)) {


		}
	}
}
